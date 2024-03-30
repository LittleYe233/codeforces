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
    let mut xsum: i32 = 0;
    let mut ysum: i32 = 0;
    let mut zsum: i32 = 0;
    let n: usize = scan.next();
    for _ in 0..n {
        let x: i32 = scan.next();
        let y: i32 = scan.next();
        let z: i32 = scan.next();
        xsum += x;
        ysum += y;
        zsum += z;
    }
    if xsum == 0 && ysum == 0 && zsum == 0 {
        writeln!(out, "YES").ok();
    } else {
        writeln!(out, "NO").ok();
    }
}
