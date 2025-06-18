#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    map<string,int> mp;

    while (t--) {
        string s;
        cin >> s;

        if (mp.count(s) == 0) {
            mp[s] = 1;
            cout << "OK" << endl;
        } else {
            int temp = mp[s];
            string next;
            do {
                next = s + to_string(temp);
                temp++;
            } while (mp.count(next));
            mp[s] = temp;
            mp[next] = 1;
            cout << next << endl;
        }
    }
    return 0;
}