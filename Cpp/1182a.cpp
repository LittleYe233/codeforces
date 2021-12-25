#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;

    cin >> n;
    
    cout << (n % 2 ? 0 : (int)pow(2, n / 2)) << endl;

    return 0;
}