#include <iostream>

using namespace std;

int main() {
    int t, n, x, a, b;

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        a = b = 0;
        for (int j = 0; j < n; ++j) {
            cin >> x;
            x % 2 ? ++a : ++b;
        }

        if (a % 2 == 0 && (b % 2 == 0 || b % 2 && a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}