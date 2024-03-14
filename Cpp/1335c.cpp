#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

// from codeforces tutorial

int main() {
    int t, n, a;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        vector<int> cnt(n + 1);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a);
            ++cnt[a];
        }
        int maxcnt = *max_element(cnt.begin(), cnt.end());
        int diff = n + 1 - count(cnt.begin(), cnt.end(), 0);
        printf("%d\n", max(min(maxcnt - 1, diff), min(maxcnt, diff - 1)));
    }

    return 0;
}

// int cnt[200001];

// int main() {
//     int t, n, diff, maxcnt, a;
//     scanf("%d", &t);
//     for (int i = 0; i < t; ++i) {
//         scanf("%d", &n);
//         for (int j = 1; j <= n; ++j) {
//             cnt[j] = 0;
//         }
//         diff = 0;
//         maxcnt = 0;
//         for (int j = 0; j < n; ++j) {
//             scanf("%d", &a);
//             if (cnt[a] > 0) {
//                 cnt[a]++;
//             } else {
//                 cnt[a] = 1;
//                 diff++;
//             }
//             maxcnt = max(maxcnt, cnt[a]);
//         }
//         printf("%d\n", max(min(diff, maxcnt - 1), min(diff - 1, maxcnt)));
//     }

//     return 0;
// }