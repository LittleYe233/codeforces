#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#ifdef DEBUG
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '[';
    if (!v.empty())
    {
        for (auto it = v.begin(); it != v.end() - 1; ++it)
        {
            os << *it << ", ";
        }
        cout << v.back();
    }
    os << ']';

    return os;
}
#endif

char change_bit(char x)
{
    return x == '1' ? '0' : '1';
}

int change_bit(int x)
{
    return x ? 0 : 1;
}

int get_bit(char x)
{
    return x - '0';
}

void solve_and_print(string s)
{
    int n = s.length(), total = 0;
    vector<int> ans(n, 0), stack[2];

    for (int i = 0; i < n; ++i)
    {
#ifdef DEBUG
        cout << "i        = " << i << endl;
#endif
        char c = change_bit(s[i]);
        int x = get_bit(c), y = get_bit(s[i]);
        if (stack[x].empty())
        {
            ++total;
            ans[i] = total;
            stack[y].push_back(total - 1);
        }
        else
        {
            int j = stack[x].back();
            stack[x].pop_back();
            stack[y].push_back(j);
            ans[i] = j + 1;
        }
#ifdef DEBUG
        cout << "stack[0] = " << stack[0] << endl;
        cout << "stack[1] = " << stack[1] << endl;
        cout << "ans      = " << ans << endl;
#endif
    }

    cout << total << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

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