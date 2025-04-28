#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q1, q2;
    int x;
    for (int i = 0; i < 5; ++i) {
        cin >> x;
        q1.push(x);
    }
    for (int i = 0; i < 5; ++i) {
        cin >> x;
        q2.push(x);
    }

    const int MAX_MOVES = 1000000;
    int moves = 0;

    while (!q1.empty() && !q2.empty() && moves < MAX_MOVES) {
        ++moves;
        int a = q1.front(); q1.pop();
        int b = q2.front(); q2.pop();

        bool firstWins;
        if (a == 0 && b == 9)        firstWins = true;
        else if (a == 9 && b == 0)   firstWins = false;
        else                         firstWins = (a > b);

        if (firstWins) {
            q1.push(a);
            q1.push(b);
        } else {
            q2.push(a);
            q2.push(b);
        }
    }

    if (q1.empty()) {
        cout << "second " << moves << "\n";
    } else if (q2.empty()) {
        cout << "first "  << moves << "\n";
    } else {
        cout << "botva\n";
    }

    return 0;
}