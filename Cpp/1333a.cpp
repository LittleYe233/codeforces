#include <iostream>

using namespace std;

int main()
{
    int t, m, n;

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m;

        cout << 'W';
        for (int j = 1; j < m; ++j)
        {
            cout << 'B';
        }
        cout << endl;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << 'B';
            }
            cout << endl;
        }
    }

    return 0;
}