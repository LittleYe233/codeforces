#include <cstring>
#include <iostream>

using namespace std;

bool judge(string s)
{
    int score = 0, l = s.length(), ll = l / 2;

    if (l % 2)
    {
        return false;
    }

    for (int i = 0; i < l; ++i)
    {
        if (s[i] == '(')
        {
            ++score;
        }
        else if (s[i] == ')')
        {
            --score;
        }
        if (score < 0 || score > ll)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    string s;

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> s;
        cout << (judge(s) ? "YES" : "NO") << endl;
    }

    return 0;
}