#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int result = -1, n, m, max_cnt = -1, t, tt;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        tt = (int)ceil(t * 1.0 / m);
        if (tt >= max_cnt) {
            max_cnt = tt;
            result = i + 1;
        }
    }
    cout << result << endl;
    return 0;
}
