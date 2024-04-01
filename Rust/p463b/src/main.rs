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
    let mut e: i32 = 0;
    let mut ans: i32 = 0;
    let mut hs = Vec::with_capacity(n + 1);
    hs.push(0);
    (0..n).for_each(|_| {
        let h: i32 = scan.next();
        hs.push(h);
    });
    (1..=n).for_each(|i| {
        let d = hs[i - 1] - hs[i];
        if e + d < 0 {
            ans += -e-d;
            e = 0;
        } else {
            e += d;
        }
    });
    writeln!(out, "{}", ans).ok();
}
