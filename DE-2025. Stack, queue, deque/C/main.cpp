#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    if (!(cin >> s)) return 0;
    int diff = 0;
    for (int i = 0, n = s.size(); i < n; ++i) {
        if ((i % 2 == 0 && s[i] == '+') ||
            (i % 2 == 1 && s[i] == '-')) {
            ++diff;  // A
            } else {
                --diff;  // B
            }
    }

    cout << (diff == 0 ? "Yes\n" : "No\n");
    return 0;
}