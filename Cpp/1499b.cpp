#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    string s;
    int a, b;

    cin >> t;
    // cin.sync();
    for (int i = 0; i < t; ++i) {
        cin >> s;
        // cin.sync();

        if (s.length() < 4) {
            cout << "YES" << endl;
            continue;
        }

        a = b = -1;
        for (int j = 1; j < s.length(); ++j) {
            if (s[j - 1] == '0' && s[j] == '0') {
                a = j;
            }
            if (s[j - 1] == '1' && s[j] == '1') {
                b = j;
            }
            if (a >= 0 && b >= 0 && a > b) {
                cout << "NO" << endl;
                goto label;
            }
        }
        cout << "YES" << endl;
        label:;
    }

    return 0;
}