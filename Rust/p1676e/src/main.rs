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

fn lower_bound<T: Ord>(v: &[T], x: &T) -> usize {
    v.binary_search_by(|probe| match probe.cmp(x) {
        Ordering::Equal => Ordering::Greater,
        ord => ord
    }).unwrap_err()
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());

    // Write code here
    let t: usize = scan.next();
    (0..t).for_each(|_| {
        let n: usize = scan.next();
        let q: usize = scan.next();
        let mut a: Vec<u32> = (0..n).map(|_| scan.next()).collect();
        a.sort_by(|a, b| b.cmp(a)); // reverse sort
        let mut aa: Vec<u32> = Vec::with_capacity(n);
        (0..n).for_each(|i| if i == 0 {
            aa.push(a[0]);
        } else {
            aa.push(a[i] + aa.last().unwrap());
        }); // prefix sum array
        (0..q).for_each(|_| {
            let m: u32 = scan.next();
            let idx = lower_bound(&aa, &m);
            if idx == aa.len() {
                writeln!(out, "{}", -1).ok();
            } else {
                writeln!(out, "{}", idx + 1).ok();
            }
        })
    });
}
