#include <iostream>
using namespace std;

int main () {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  for (int i = 0; i < a.length(); i++) {
    a[i] = tolower(a[i]);
    b[i] = tolower(b[i]);
  }

  if (a < b) {
    cout << "-1" << endl;
  } else if (a > b) {
    cout << "1" << endl;
  } else {
    cout << "0" << endl;
  }
  return 0;
}