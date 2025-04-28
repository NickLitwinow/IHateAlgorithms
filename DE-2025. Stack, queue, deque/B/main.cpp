#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    string minS(n+1, '{');
    for(int i = n-1; i >= 0; --i)
        minS[i] = min(s[i], minS[i+1]);

    stack<char> st;
    string u;
    for(int i = 0; i < n; ++i){
        st.push(s[i]);
        while(!st.empty() && st.top() <= minS[i+1]){
            u += st.top();
            st.pop();
        }
    }
    while(!st.empty()){
        u += st.top();
        st.pop();
    }

    cout << u;
    return 0;
}