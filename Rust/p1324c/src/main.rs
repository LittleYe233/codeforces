use std::cmp::max;
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

fn check(s: &Vec<char>) -> usize {
    let mut v: Vec<usize> = Vec::new();
    v.push(0);
    for (i, c) in s.iter().enumerate() {
        if *c == 'R' {
            v.push(i + 1);
        }
    }
    let l = v.len();
    let m = (1..l).max_by_key(|i| v[*i] - v[*i - 1]).unwrap_or(usize::MAX);
    // println!("{:?} {}", v, m);
    if m == usize::MAX {
        s.len() + 1
    } else {
        max(v[m] - v[m - 1], s.len() + 1 - v[l - 1])
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // Write code here
    let t: usize = scan.next();
    for _ in 0..t {
        let s: String = scan.next();
        let v: Vec<char> = s.chars().collect();
        writeln!(out, "{}", check(&v)).ok();
    }
}
