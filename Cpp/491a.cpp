#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    for (int i = b + 1; i <= a + b + 1; ++i)
    {
        cout << i << ' ';
    }
    for (int i = b; i > 0; --i)
    {
        cout << i << ' ';
    }

    return 0;
}