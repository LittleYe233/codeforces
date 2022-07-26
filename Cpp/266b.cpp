#include <cstring>
#include <iostream>
#include <stdlib.h>

using namespace std;

// brute force
string solve(int n, int t, string s)
{
    int l = s.length();

    for (int i = 0; i < t; ++i)
    {
        int j = 0;
        while (j < l - 1)
        {
            if (s[j] == 'B' && s[j + 1] == 'G')
            {
                s[j] = 'G';
                s[j + 1] = 'B';
                j += 2;
            }
            else
            {
                ++j;
            }
        }
    }

    return s;
}

int main()
{
    int n, t;
    string s, a;

    cin >> n >> t;
    cin >> s;

    a = solve(n, t, s);

    cout << a << endl;

    return 0;
}