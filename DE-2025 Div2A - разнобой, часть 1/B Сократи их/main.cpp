#include <iostream>
using namespace std;

int main () {
    unsigned short n;
    cin >> n;
    for (unsigned short i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() > 10) {
          cout << s[0] << s.length()-2 << s[s.length()-1] << endl;
        } else {
          cout << s << endl;
        }
    }
    return 0;
}