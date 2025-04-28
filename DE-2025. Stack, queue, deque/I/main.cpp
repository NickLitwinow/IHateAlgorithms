#include <iostream>
#include <deque>
using namespace std;

void rebalance(deque<int>& left, deque<int>& right, int n) {
    int desired = (n + 1) / 2;
    if ((int)left.size() > desired) {
        right.push_front(left.back());
        left.pop_back();
    } else if ((int)left.size() < desired) {
        left.push_back(right.front());
        right.pop_front();
    }
}

int main() {
    int N;
    cin >> N;

    deque<int> left, right;
    int n = 0;

    for (int qi = 0; qi < N; ++qi) {
        char op;
        cin >> op;
        if (op == '+') {
            int id;
            cin >> id;
            right.push_back(id);
            ++n;
            rebalance(left, right, n);
        }
        else if (op == '*') {
            int id;
            cin >> id;
            left.push_back(id);
            ++n;
            rebalance(left, right, n);
        }
        else {
            int ans = left.front();
            left.pop_front();
            --n;
            cout << ans << "\n";
            rebalance(left, right, n);
        }
    }

    return 0;
}