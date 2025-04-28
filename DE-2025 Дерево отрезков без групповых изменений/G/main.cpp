#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> freeSpots;
    for (int i = 1; i <= n; ++i)
        freeSpots.insert(i);

    while (m--) {
        string cmd;
        int x;
        cin >> cmd >> x;
        if (cmd == "enter") {
            auto it = freeSpots.lower_bound(x);
            if (it == freeSpots.end())
                it = freeSpots.begin();
            int spot = *it;
            cout << spot << "\n";
            freeSpots.erase(it);
        } else {
            freeSpots.insert(x);
        }
    }

    return 0;
}