#include <iostream>
#include <string>
using namespace std;

int main () {
  int n, del = 0, counter = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x') {
      counter++;
      if (counter >= 3) {
        del++;
      }
    } else {
      counter = 0;
    }
  }
  cout << del << endl;
  return 0;
}