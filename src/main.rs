
use std::env::args;
use std::fs::File;
use std::io::{BufReader, Read};
use std::io::Write;

type Token = String;

enum TokenType {
    // Single-character tokens
    LeftParen, RightParen, LeftBrace, RightBrace,
    Comma, Dot, Minus, Plus, Semicolon, Slash, Star,

    // One or two character tokens
    Bang, BangEqual,
    Equal, EqualEqual,
    Greater, GreaterEqual,
    Less, LessEqual,

    // Literals
    Identifier, String, Number,

    // Keywords
    And, Class, Else, False, Fun, For, If, Nil, Or,
    Print, Return, Super, This, True, Var, While,

    EOF,
}

struct Interpreter {
    had_error: bool,
}

impl Interpreter {
    fn new() -> Self {
        Interpreter { had_error: false }
    }

    fn run(&mut self, source: String) {
        let tokens: Vec<Token> = source.split_whitespace().map(|s| s.to_string()).collect();
        println!("{:?}", tokens);
    }

    fn run_file(&mut self, path: &str) {
        let file = File::open(path).expect("Failed to open file");
        let bytes = BufReader::new(file).bytes();
        self.run(bytes.map(|b| b.unwrap() as char).collect());
        if self.had_error {
            std::process::exit(65);
        }

    }

    fn run_prompt(&mut self) {
        loop {
            print!("> ");
            let _ = std::io::stdout().flush();
            let mut line = String::new();
            std::io::stdin().read_line(&mut line).expect("Failed to read line");
            // break if line is EOF
            if line == "exit\n"{
                break;
            }
            self.run(line);
            self.had_error = false;
        }
    }

    fn error(&mut self, line: usize, message: &str) {
        self.report(line, "", message);
    }

    fn report(&mut self, line: usize, loc: &str, message: &str) {
        eprintln!("[line {}] Error {}: {}", line, loc, message);
    }
}


fn main() {
    let args: Vec<String> = args().collect();
    let mut interpreter = Interpreter::new();

    if args.len() < 1 {
        println!("Usage: {} [script]", args[0]);
        std::process::exit(64);
    }else if args.len() == 1 {
        interpreter.run_prompt();
    }else {
        interpreter.run_file(&args[1]);
    }
}
