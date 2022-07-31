#include <iostream>

using namespace std;

int main()
{
    int t, n, a;
    long long positive;

    cin >> t;

    while (t--)
    {
        cin >> n;
        positive = 0;
        while (n--)
        {
            cin >> a;
            positive += a;
            if (positive < 0)
            {
                positive = 0;
            }
        }
        cout << positive << endl;
    }

    return 0;
}