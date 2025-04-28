#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    stack<int> st;
    st.push(-1);

    int maxLen = 0;
    long long count = 0;

    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                int len = i - st.top();
                if (len > maxLen) {
                    maxLen = len;
                    count = 1;
                } else if (len == maxLen) {
                    ++count;
                }
            }
        }
    }

    if (maxLen == 0) count = 1;
    cout << maxLen << " " << count << "\n";
    return 0;
}