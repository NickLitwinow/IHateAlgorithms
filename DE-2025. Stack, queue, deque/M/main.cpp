#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> res(n);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            res[i] = -1;
        } else {
            res[i] = st.top() + 1;
        }
        st.push(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}