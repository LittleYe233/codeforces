#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    string s;

    cin >> s;

    cout << s + string(s.rbegin(), s.rend()) << endl;

    return 0;
}