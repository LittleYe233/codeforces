#[allow(unused_imports)]
use std::io::{BufWriter, stdin, stdout, Write};
use std::{cmp::{max, min}, collections::HashMap};

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

#[derive(Debug)]
struct MN(usize, usize);

fn solve(v: &[u32]) -> bool {
    let mut m: HashMap<u32, MN> = HashMap::new();
    for (i, j) in v.iter().enumerate() {
        if m.contains_key(j) {  // can be simplified
            let mn = m.get(j).unwrap();
            m.insert(*j, MN(min(mn.0, i), max(mn.1, i)));
        } else {
            m.insert(*j, MN(i, i));
        }
    }
    for (_, mn) in &m {
        if mn.1 - mn.0 >= 2 {
            return true;
        }
    }
    false
}

// // codeforces' tutorial:
// fn solve(v: &[u32]) -> bool {
//     let l = v.len();
//     for i in 0..l {
//         for j in (i + 2)..l {
//             if v[i] == v[j] {
//                 return true;
//             }
//         }
//     }
//     false
// }

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // Write code here
    let t: usize = scan.next();
    for _ in 0..t {
        let n: usize = scan.next();
        let v: Vec<u32> = (0..n).map(|_| scan.next()).collect();
        if solve(&v) {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}
