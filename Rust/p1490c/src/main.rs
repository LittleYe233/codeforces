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

fn check(x: u64) -> bool {
    for a in 1..=((x as f64).cbrt().floor() as u64) {
        let b = ((x - a * a * a) as f64).cbrt();
        if b.fract() == 0.0 && b != 0.0 {
            return true;
        }
    }
    false
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // Write code here
    let t: usize = scan.next();
    for _ in 0..t {
        let x: u64 = scan.next();
        if check(x) {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
