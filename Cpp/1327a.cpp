#include <cstdio>

using namespace std;

bool check(long long n, long long k) {
    return (n >= k * k) && (n % 2 == k % 2);
}

int main() {
    long long t, n, k;
    scanf("%lld", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%lld%lld", &n, &k);
        if (check(n, k)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}