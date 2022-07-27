#include <iostream>

using namespace std;

int solve(int k, int l, int m, int n, int d)
{
    int ans = 0;

    for (int i = 1; i <= d; ++i)
    {
        if (!(i % k && i % l && i % m && i % n))
        {
            ++ans;
        }
    }

    return ans;
}

int main()
{
    int k, l, m, n, d;

    cin >> k >> l >> m >> n >> d;

    cout << solve(k, l, m, n, d) << endl;

    return 0;
}