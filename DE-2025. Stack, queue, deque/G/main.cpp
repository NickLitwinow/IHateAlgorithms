#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    if (!getline(cin, s)) return 0;

    stack<char> st;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                cout << "no\n";
                return 0;
            }
            char t = st.top(); st.pop();
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                cout << "no\n";
                return 0;
                }
        }
    }

    cout << (st.empty() ? "yes\n" : "no\n");
    return 0;
}