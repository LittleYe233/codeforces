#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int t, n, a[100];

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        while (n--)
        {
            cout << a[n] << ' ';
        }
        cout << endl;
    }

    return 0;
}