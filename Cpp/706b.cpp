#include <bits/stdc++.h>

using namespace std;

int x[100001];

int main() {
    int n, q, m;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);

    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> m;
        cout << upper_bound(x + 1, x + n + 1, m) - x - 1 << endl;
    }

    return 0;
}