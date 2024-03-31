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
    let k: usize = scan.next();
    let mut hs: Vec<i32> = Vec::with_capacity(n);
    for _ in 0..n {
        let h: i32 = scan.next();
        hs.push(h);
    }
    let mut hhs: Vec<i32> = Vec::with_capacity(n + 1);
    hhs.push(0);
    for i in 0..n {
        hhs.push(&hs[i] + &hhs[i]);
    }
    let mut m = 0x7fffffff;
    let mut mpos = 0;
    for i in k..=n {
        if hhs[i] - hhs[i - k] < m {
            m = hhs[i] - hhs[i - k];
            mpos = i - k + 1;
        }
    }
    writeln!(out, "{}", mpos).ok();
}
