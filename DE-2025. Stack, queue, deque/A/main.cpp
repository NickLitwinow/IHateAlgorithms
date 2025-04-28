#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    const unsigned long long LIMIT = (1ULL << 32) - 1;
    int l;
    cin >> l;

    stack<unsigned long long> mult;
    mult.push(1ULL);
    unsigned long long x = 0;

    for (int i = 0; i < l; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            unsigned long long inc = mult.top();
            if (x + inc > LIMIT) {
                cout << "OVERFLOW!!!\n";
                return 0;
            }
            x += inc;
        }
        else if (cmd == "for") {
            unsigned long long n;
            cin >> n;
            unsigned long long top = mult.top();
            if (top > LIMIT / n) {
                mult.push(LIMIT + 1);
            } else {
                mult.push(top * n);
            }
        }
        else if (cmd == "end") {
            mult.pop();
        }
    }

    cout << x << "\n";
    return 0;
}