#include <iostream>
#include <unordered_set>
using namespace std;

int main () {
    unordered_set<char> set;
    string s;

    cin>>s;

    for (int i=0; i<s.length(); i++) {
        set.insert(s[i]);
    }

    if (set.size() % 2 == 0) {
      cout << "CHAT WITH HER!" << endl;
    } else {
      cout << "IGNORE HIM!" << endl;
    }
    return 0;
}