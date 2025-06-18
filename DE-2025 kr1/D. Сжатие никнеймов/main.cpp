#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        string nickname;
        cin>>nickname;

        int length = nickname.length();
        if (length > 10) {
            cout << nickname[0] << (length - 2) << nickname[length - 1] << endl;
        } else {
            cout << nickname << endl;
        }
    }
    return 0;
}