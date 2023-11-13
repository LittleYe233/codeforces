#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int t, n, a, tt;
    long long unsigned int s;
    unordered_map<int, int> m;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        m.clear();
        s = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a);
            tt = a - j - 1;
            if (m.find(tt) == m.end()) {
                m.insert({tt, 1});
            } else {
                m[tt]++;
            }
        }
        for (const auto& kv : m) {
            if (kv.second > 1) {
                s += (long long unsigned int)(kv.second - 1) * kv.second / 2;
            }
        }
        printf("%lld\n", s);
    }
    return 0;
}
