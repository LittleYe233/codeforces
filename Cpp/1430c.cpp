#include <iostream>

using namespace std;

void solveAndPrint(int n)
{
    cout << 2 << endl;
    cout << n - 1 << ' ' << n << endl;
    for (int i = 2; i < n; ++i)
    {
        cout << n - i << ' ' << n - i + 2 << endl;
    }
}

int main()
{
    int t, n;

    cin >> t;
    while (t--)
    {
        cin >> n;
        solveAndPrint(n);
    }

    return 0;
}