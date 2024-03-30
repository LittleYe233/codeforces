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
    let n = scan.next::<u32>() as f64;
    let m = scan.next::<u32>() as f64;
    let a = scan.next::<u32>() as f64;
    // writeln!(out, "{}", (n + a - 1) / a * (m + a - 1) / a).ok();
    writeln!(out, "{}", (n / a).ceil() * (m / a).ceil()).ok();
}
