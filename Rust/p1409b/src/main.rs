use std::cmp::{max, min};
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

fn solve(a: i64, b: i64, x: i64, y: i64, n: i64) -> i64 {
    let (p, q) = (a - x, b - y);
    let a1;
    let a2;
    let b1;
    let b2;
    if p <= n {
        a1 = x;
        b1 = max(y, b - n + p);
    } else {
        a1 = a - n;
        b1 = b;
    }
    if q <= n {
        b2 = y;
        a2 = max(x, a - n + q);
    } else {
        b2 = b - n;
        a2 = a;
    }
    min(a1 * b1, a2 * b2)
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // Write code here
    let t: usize = scan.next();
    for _ in 0..t {
        let a: i64 = scan.next();
        let b: i64 = scan.next();
        let x: i64 = scan.next();
        let y: i64 = scan.next();
        let n: i64 = scan.next();
        writeln!(out, "{}", solve(a, b, x, y, n)).ok();
    }
}
