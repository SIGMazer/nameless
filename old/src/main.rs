mod interpreter;
mod scanner;
mod token;

use interpreter::Interpreter;
use std::env::args;

fn main() {
    let args: Vec<String> = args().collect();
    let mut interpreter = Interpreter::new();

    if args.len() < 1 {
        println!("Usage: {} [script]", args[0]);
        std::process::exit(64);
    } else if args.len() == 1 {
        interpreter.run_prompt();
    } else {
        interpreter.run_file(&args[1]);
    }
}
