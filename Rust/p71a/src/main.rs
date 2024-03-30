#[allow(unused_imports)]
use std::io::{BufWriter, stdin, stdout, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // Write code here
    let n: usize = scan.next();
    for _ in 0..n {
        let s: String = scan.next();
        let sc: Vec<char> = s.chars().collect();
        if s.len() > 10 {
            writeln!(out, "{}{}{}", sc[0], s.len() - 2, sc[s.len() - 1]).ok();
        } else {
            writeln!(out, "{}", s).ok();
        }
    }
}
