use std::cmp::Ordering;
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

// @see https://stackoverflow.com/a/75790348/12002560
fn upper_bound(v: &Vec<i32>, x: i32) -> usize {
    v.binary_search_by(|probe| match probe.cmp(&x) {
        Ordering::Equal => Ordering::Less,
        ord => ord
    }).unwrap_err()
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // Write code here
    let n: usize = scan.next();
    let mut x: Vec<i32> = Vec::with_capacity(n);
    for _ in 0..n {
        let xi: i32 = scan.next();
        x.push(xi);
    }
    x.sort();
    let q: usize = scan.next();
    for _ in 0..q {
        let m: i32 = scan.next();
        writeln!(out, "{}", upper_bound(&x, m)).ok();
    }
}
