#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (b * 1.0 / m >= a) {
        cout << a * n << endl;
    } else {
        cout << min((n / m) * b + (n % m) * a, (int)ceil(n * 1.0 / m) * b) << endl;
    }
    return 0;
}