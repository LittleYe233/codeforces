#include <iostream>

using namespace std;

int main()
{
    int n, k, t;

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> k;
        if (n <= k)
        {
            cout << k / n + (k % n ? 1 : 0) << endl;
        }
        else
        {
            cout << (n % k ? 2 : 1) << endl;
        }
    }

    return 0;
}