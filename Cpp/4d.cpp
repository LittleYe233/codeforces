#include <iostream>
#include <algorithm>

using namespace std;

struct Envelope {
    int w;
    int h;
    int id;
} e[5001];
int f[5001], ids[5001];

bool cmp_w(Envelope, Envelope);

int main() {
    int n, w, h, l = 0;

    cin >> n >> w >> h;
    for (int i = 1; i <= n; ++i) {
        ++l;
        cin >> e[l].w >> e[l].h;
        if (e[l].w <= w || e[l].h <= h) {
            continue;
        }
        e[l].id = i;
    }
    
    if (l == 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(e + 1, e + l + 1, cmp_w);
    f[1] = 1;
    ids[1] = 1;
    for (int i = 2; i <= l; ++i) {
        for (int j = 1; j < i; ++j) {
            if (e[j].h < e[i].h) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    cout << f[l] << endl;

    return 0;
}

bool cmp_w(Envelope a, Envelope b) {
    return a.w < b.w;
}