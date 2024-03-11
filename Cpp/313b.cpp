#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int a[100001];

int main() {
    string s;
    int n, l, r;
    
    getline(cin, s);
    for (int i = 1; i < s.length(); ++i) {
        if (s[i - 1] == s[i]) {
            a[i] = a[i - 1] + 1;
        } else {
            a[i] = a[i - 1];
        }
    }
    a[s.length()] = a[s.length() - 1];
    // for (int i = 1; i <= s.length(); ++i) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    scanf("%d", &n);
    for (int t = 0; t < n; ++t) {
        scanf("%d%d", &l, &r);
        printf("%d\n", a[r - 1] - a[l - 1]);
    }

    return 0;
}
