#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define MAX_PRIME (20011) // 10007 and 20011 are primes.

using namespace std;

bool isPrime(int x)
{
    if (x == 1)
    {
        return false;
    }
    if (x == 2)
    {
        return true;
    }
    if (x % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i <= int(floor(sqrt(x))); i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

vector<int> updatePrimes(int maxn, vector<int> primes)
{
    int lastPrime = 2;

    if (primes.size())
    {
        lastPrime = primes.back();
    }
    else
    {
        primes.push_back(2);
    }

    for (int i = lastPrime + (lastPrime == 2 ? 1 : 2); i <= maxn; i += 2)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    return primes;
}

vector<int> updatePrimes(int maxn)
{
    return updatePrimes(maxn, vector<int>());
}

int solve(int d, vector<int> primes)
{
    vector<int>::iterator index1 = lower_bound(primes.begin(), primes.end(), 1 + d);
    vector<int>::iterator index2 = lower_bound(primes.begin(), primes.end(), *index1 + d);

    return *index1 * *index2;
}

int main()
{
    int t, d;
    vector<int> primes = updatePrimes(MAX_PRIME);

    cin >> t;

    while (t--)
    {
        cin >> d;
        cout << solve(d, primes) << endl;
    }

    return 0;
}