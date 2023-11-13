#include <iostream>
#include <string>

using namespace std;

char invert(char c) {
    return '0' + ('9' - c);
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] > '4' && (i == 0 && s[i] != '9' || i > 0)) {
            printf("%c", invert(s[i]));
        } else {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
}
