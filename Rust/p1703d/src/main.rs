#[allow(unused_imports)]
use std::io::{BufWriter, stdin, stdout, Write};
use std::collections::HashSet;

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
        let s: Vec<String> = (0..n).map(|_| scan.next()).collect();
        let mut hs: HashSet<String> = HashSet::new();
        for ss in &s {
            hs.insert(ss.clone());
        }
        // println!("{:?}", &hs);
        for ss in &s {
            let mut flag: bool = false;
            let sss = ss.clone();
            for i in 1..sss.len() {
                let pref: String = sss.chars().take(i).collect();
                let suff: String = sss.chars().skip(i).collect();
                // println!("{} {}", &pref, &suff);
                if hs.contains(&pref) && hs.contains(&suff) {
                    flag = true;
                    break;
                }
            }
            write!(out, "{}", if flag {
                "1"
            } else {
                "0"
            }).ok();
        }
        writeln!(out, "").ok();
    });
}
