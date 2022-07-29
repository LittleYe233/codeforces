#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < 2 * n + 1; ++i)
    {
        int k = abs(n - i);
        
        cout << string(2 * k, ' ');
        for (int j = 0; j <= n - k; ++j)
        {
            (k == n ? (cout << j) : (cout << j << ' '));
        }
        for (int j = n - k - 1; j >= 0; --j)
        {
            (j ? (cout << j << ' ') : (cout << j));
        }
        cout << endl;
    }

    return 0;
}