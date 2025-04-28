#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream in(line);

    stack<long long> st;
    string tok;
    while (in >> tok) {
        if (tok == "+" || tok == "-" || tok == "*") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            long long res = (tok == "+" ? a + b
                            : tok == "-" ? a - b
                                         : a * b);
            st.push(res);
        } else {
            st.push(atoll(tok.c_str()));
        }
    }

    cout << st.top() << "\n";
    return 0;
}