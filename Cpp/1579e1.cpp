#include <iostream>
#include <deque>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const deque<T>& d)
{
    for (deque<int>::size_type i = 0; i < d.size() - 1; ++i)
    {
        os << d[i] << ' ';
    }
    os << d.back();

    return os;
}

deque<int> solve(int n)
{
    int a;
    deque<int> ans;
    
    // make sure the deque is not empty
    cin >> a;
    ans.push_back(a);
    while (--n)
    {
        cin >> a;
        if (a < ans.front())
        {
            ans.push_front(a);
        }
        else
        {
            ans.push_back(a);
        }
    }

    return ans;
}

int main()
{
    int t, n;
    deque<int> ans;

    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = solve(n);
        cout << ans << endl;
    }

    return 0;
}