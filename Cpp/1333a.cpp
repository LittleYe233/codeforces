#include <iostream>

#define MAXN (100)
#define MAXM (100)

using namespace std;

char arr[MAXN][MAXM]; // {B, W}

void printMatrix(int n, int m, bool reversed)
{
    if (reversed)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
}

void solveAndPrint(int n, int m)
{
    bool isReversed = false;

    if (n < m)
    {
        isReversed = true;
        // swap two numbers
        n = n - m;
        m = n + m;
        n = m - n;
    }

    if (n % 2 && m % 2)
    {
        for (int j = 0; j < m - 1; j += 2)
        {
            for (int i = 0; i < n; ++i)
            {
                arr[i][j] = 'B';
            }
        }
        for (int j = 1; j < m; j += 2)
        {
            for (int i = 0; i < n; ++i)
            {
                arr[i][j] = 'W';
            }
        }
        for (int i = 0; i < n; i += 2)
        {
            arr[i][m - 1] = 'B';
        }
        for (int i = 1; i < n; i += 2)
        {
            arr[i][m - 1] = 'W';
        }
        printMatrix(n, m, isReversed);
    }
    else if (m == 2)
    {
        arr[n - 1][0] = arr[n - 1][1] = 'B';
        for (int i = 0; i < n - 1; i += 2)
        {
            arr[i][0] = 'B';
            arr[i][1] = 'W';
        }
        for (int i = 1; i < n - 1; i += 2)
        {
            arr[i][1] = 'B';
            arr[i][0] = 'W';
        }
        printMatrix(n, m, isReversed);
    }
    else
    {
        // It shouldn't be executed as expected.
        cout << endl;
    }
}

int main()
{
    int t, m, n;

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m;
        solveAndPrint(n, m);
    }

    return 0;
}