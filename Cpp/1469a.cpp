#include <cstring>
#include <iostream>

using namespace std;


int main()
{
    int t;
    string s;

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> s;
        if (s.length() % 2 == 0 && s[0] != ')' && s[s.length() - 1] != '(')
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}