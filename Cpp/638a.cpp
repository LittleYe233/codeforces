#include <iostream>

using namespace std;

int main()
{
    int n, a;
    
    cin >> n >> a;

    cout << (a % 2 ? (a + 1) / 2 : (n + 2 - a) / 2) << endl;

    return 0;
}