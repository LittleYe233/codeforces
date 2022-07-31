#include <algorithm>
#include <iostream>

using namespace std;

int a[100000];

int main()
{
    int n, p = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    cout << (n - 1) / 2 << endl;
    sort(a, a + n);
    while (p++ < n / 2)
    {
        cout << a[n - p] << ' ' << a[p - 1] << ' ';
    }
    if (n % 2)
    {
        cout << a[p - 1];
    }
    cout << endl;

    return 0;
}