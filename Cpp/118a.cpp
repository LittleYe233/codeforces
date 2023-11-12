#include <iostream>
#include <string>

using namespace std;

bool is_vowel(char c) {
    return c == 'A' || c == 'O' || c == 'Y' || c == 'E' || c == 'U' || c == 'I' || c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i';
}

int main() {
    string s;
    
    cin >> s;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (is_vowel(s[i])) {
            continue;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            printf(".%c", s[i] + 'a' - 'A');
        } else {
            printf(".%c", s[i]);
        }
    }
    printf("\n");

    return 0;
}
