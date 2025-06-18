#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int x;
        bool seen[24*60] = {false};
        cin >> s >> x;

        int h = (s[0] - '0') * 10 + (s[1] - '0');
        int m = (s[3] - '0') * 10 + (s[4] - '0');
        int res = 0, temp = h * 60 + m;

        while (!seen[temp]) {
            seen[temp] = true;
            int hh = temp / 60;
            int mm = temp % 60;
            if (hh / 10 == mm % 10 && hh % 10 == mm / 10) {
                res++;
            }

            temp = (temp + x) % (24 * 60);
        }
        cout << res << endl;
    }
    return 0;
}