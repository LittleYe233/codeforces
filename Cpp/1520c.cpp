#include <iostream>

using namespace std;

void solveAndPrint(int n)
{
    const int nn = n * n;

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    if (n == 2)
    {
        cout << -1 << endl;
        return;
    }

    if (n % 2)
    {
        for (int i = 0; i < nn; ++i)
        {
            if (i % 2)
            {
                cout << (nn + i) / 2 + 1 << ' ';
            }
            else
            {
                cout << i / 2 + 1 << ' ';
            }
            if ((i + 1) % n == 0)
            {
                cout << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < nn; ++i)
        {
            if (i % 2)
            {
                cout << (nn + i + 1) / 2 << ' ';
            }
            else
            {
                cout << i / 2 + 1 << ' ';
            }
            if ((i + 1) % n == 0)
            {
                cout << endl;
            }
        }
    }
}

int main()
{
    int t, n;

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        solveAndPrint(n);
    }

    return 0;
}