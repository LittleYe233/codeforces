use std::cmp::min;
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
    let t: usize = scan.next();
    (0..t).for_each(|_| {
        let n: usize = scan.next();
        let a: Vec<u32> = (0..n).map(|_| scan.next()).collect();
        let mut ans = 0;
        let mut m = *a.last().unwrap();
        (0..n-1).rev().for_each(|i| {
            if a[i] > m {
                ans += 1;
            }
            m = min(m, a[i]);
        });
        writeln!(out, "{}", ans).ok();
    });
}
