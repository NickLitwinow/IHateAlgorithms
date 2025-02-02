#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    bool is_palindrome = true;
    for (int i=0; i<k; i++) {
      if (s[i] != s[n - 1 - i]) {
        is_palindrome = false;
        break;
      }
    }

    if (k == 0) {
      cout << "YES" << endl;
    } else if (is_palindrome && k * 2 < n) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}