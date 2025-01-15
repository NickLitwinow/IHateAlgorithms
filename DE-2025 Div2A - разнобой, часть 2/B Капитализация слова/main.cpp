#include <iostream>
#include <vector>
using namespace std;

int main () {
  string s, res;
  getline(cin, s);
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) {
      res += toupper(s[i]);
    } else {
      res += s[i];
    }
  }
  cout << res << endl;
  return 0;
}