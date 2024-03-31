use std::fs::File;
use std::io::{BufReader, Read, Write};

type Token = String;

pub struct Interpreter {
    pub had_error: bool,
}

impl Interpreter {
    pub fn new() -> Self {
        Interpreter { had_error: false }
    }

    pub fn run(&mut self, source: String) {
        let tokens: Vec<Token> = source.split_whitespace().map(|s| s.to_string()).collect();
        println!("{:?}", tokens);
    }

    pub fn run_file(&mut self, path: &str) {
        let file = File::open(path).expect("Failed to open file");
        let bytes = BufReader::new(file).bytes();
        self.run(bytes.map(|b| b.unwrap() as char).collect());
        if self.had_error {
            std::process::exit(65);
        }
    }

    pub fn run_prompt(&mut self) {
        loop {
            print!("> ");
            let _ = std::io::stdout().flush();
            let mut line = String::new();
            std::io::stdin()
                .read_line(&mut line)
                .expect("Failed to read line");
            // break if line is EOF
            if line == "exit\n" {
                break;
            }
            self.run(line);
            self.had_error = false;
        }
    }

    pub fn error(line: usize, message: &str) {
        eprintln!("[line {}] Error: {}", line, message);
    }

    pub fn report(line: usize, loc: &str, message: &str) {
        eprintln!("[line {}] Error {}: {}", line, loc, message);
    }
}
