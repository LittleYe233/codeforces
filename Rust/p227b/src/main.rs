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
    let mut v: Vec<usize> = vec![0; n + 1];
    (0..n).for_each(|i| {
        let a: usize = scan.next();
        v[a] = i + 1;
    });
    let m: usize = scan.next();
    let mut p: usize = 0;
    let mut q: usize = 0;
    (0..m).for_each(|_| {
        let a: usize = scan.next();
        p += v[a];
        q += n + 1 - v[a];
    });
    writeln!(out, "{} {}", p, q).ok();
}
