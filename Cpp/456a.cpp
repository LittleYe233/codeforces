#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

pair<int, int> a[100001];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n, b;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &(a+i)->first, &(a+i)->second);
    }
    sort(a, a + n, cmp);
    b = a->second;
    for (int i = 1; i < n; ++i) {
        if ((a+i)->second < b) {
            printf("Happy Alex\n");
            return 0;
        }
        b = (a+i)->second;
    }
    printf("Poor Alex\n");
    return 0;
}
