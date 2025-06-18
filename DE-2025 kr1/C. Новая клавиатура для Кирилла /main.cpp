#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        string s;
        char max = 'a';
        cin >> n >> s;

        for (int i = 0; i < n; i++) {
            if (s[i] > max) {
                max = s[i];
            }
        }
        cout << max - 'a' + 1 << endl;
    }
    return 0;
}