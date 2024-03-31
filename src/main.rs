
use std::env::args;
use std::fs::File;
use std::io::{BufReader, Read};
use std::io::Write;

type Token = String;

fn run(source: String) {
    let tokens: Vec<Token> = source.split_whitespace().map(|s| s.to_string()).collect();

    println!("{:?}", tokens);
}

fn run_file(path: &str) {
    let file = File::open(path).expect("Failed to open file");
    let bytes = BufReader::new(file).bytes();
    run(bytes.map(|b| b.unwrap() as char).collect());

}

fn run_prompt() {
    loop {
        print!("> ");
        let _ = std::io::stdout().flush();
        let mut line = String::new();
        std::io::stdin().read_line(&mut line).expect("Failed to read line");
        // break if line is EOF
        if line == "exit\n"{
            break;
        }
        run(line);
    }
}

fn main() {
    let args: Vec<String> = args().collect();

    if args.len() < 1 {
        println!("Usage: {} [script]", args[0]);
        return;
    }else if args.len() == 1 {
        run_prompt();
    }else {
        run_file(&args[1]);
    }
}
