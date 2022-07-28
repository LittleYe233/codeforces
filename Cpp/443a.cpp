#include <cstring>
#include <iostream>

using namespace std;

int solve(string s)
{
    int cnt[26] = {0}, ans = 0;

    for (int i = 1; i < s.length() - 1; ++i)
    {
        if (s[i] != ',' && s[i] != ' ')
        {
            ++cnt[s[i] - 'a'];
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[i])
        {
            ++ans;
        }
    }

    return ans;
}

int main()
{
    string s;

    getline(cin, s);

    cout << solve(s) << endl;

    return 0;
}