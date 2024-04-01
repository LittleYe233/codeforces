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

// too slow!
// fn get_digit_sum(x: u64) -> u32 {
//     x.to_string().chars().map(|d| d.to_digit(10).unwrap()).sum()
// }

fn get_digit_sum(x: u64) -> u32 {
    let mut ans: u32 = 0;
    let mut y = x;
    while y != 0 {
        ans += (y % 10) as u32;
        y /= 10;
    }
    ans
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // Write code here
    let mut v: Vec<u64> = Vec::with_capacity(10000);
    let mut i = 19;
    loop {
        if get_digit_sum(i) == 10 {
            v.push(i);
            if (&v).len() == 10000 {
                break;
            }
        }
        i += 9;  // codeforces' advice
    }
    // println!("{:?}", &v);
    let n: usize = scan.next();
    writeln!(out, "{}", v[n - 1]).ok();
}
