#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char change_bit(char x)
{
    return x == '1' ? '0' : '1';
}

void solve_and_print(string s)
{
    int n = s.length();
    vector<int> ans(n, 0);
    vector<char> ss;

    for (int i = 0; i < n; ++i)
    {
        bool found = false;
        char c = change_bit(s[i]);
        for (int j = 0; j < ss.size(); ++j)
        {
            if (ss[j] == c)
            {
                found = true;
                ss[j] = s[i];
                ans[i] = j + 1; // answer should start with 1
                break;
            }
        }
        if (!found)
        {
            ss.push_back(s[i]);
            ans[i] = ss.size();
        }
    }

    cout << ss.size() << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int t, n;
    string s;

    cin >> t;

    while (t--)
    {
        cin >> n >> s;
        solve_and_print(s);
    }

    return 0;
}