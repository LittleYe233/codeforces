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

int calc_m1(long long unsigned k, int a)
{
    double a1, a2, a3, a4, a5;

    a1 = log(a);
    a2 = log(a + 1);
    a3 = 10 * a2;
    a4 = log(k);
    a5 = (a3 - a4) / (a2 - a1);

    return int(better_floor(a5));
}

int calc_m2(long long unsigned k, int a)
{
    double a1, a2, a3;

    a1 = pow(a + 1, 10) / k;
    a2 = (a + 1) * 1.0 / a;
    a3 = log(a1) / log(a2);

    return int(better_floor(a3));
}

int main()
{
    long long unsigned k;
    int a, m;

    cin >> k;

    a = int(pow(k, 0.1));
    // m = calc_m1(k, a);
    m = calc_m2(k, a);

    for (int i = 0; i < m; ++i)
    {
        cout << string(a, base[i]);
    }
    for (int i = m; i < 10; ++i)
    {
        cout << string(a + 1, base[i]);
    }

    return 0;
}