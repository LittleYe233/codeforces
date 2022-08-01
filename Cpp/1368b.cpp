#include <cmath>
#include <cstring>
#include <iostream>
#define EPS (1e-14)

using namespace std;

const string base("codeforces");

double better_floor(double x)
{
    double y = ceil(x);
    
    return (y - x < EPS ? y : floor(x));
}

int calc_m(long long unsigned k, int a)
{
    long long unsigned l = 1;
    int m = 10;

    for (int i = 0; i < m; ++i)
    {
        l *= a;
    }
    while (l < k && m-- >= 0)
    {
        l = l * (a + 1) / a;
    }

    return m;
}

int main()
{
    long long unsigned k;
    int a, m;

    cin >> k;

    a = int(better_floor(pow(k, 0.1)));
    m = calc_m(k, a);

    for (int i = 0; i < 10 - m; ++i)
    {
        cout << string(a + 1, base[i]);
    }
    for (int i = 10 - m; i < 10; ++i)
    {
        cout << string(a, base[i]);
    }

    return 0;
}