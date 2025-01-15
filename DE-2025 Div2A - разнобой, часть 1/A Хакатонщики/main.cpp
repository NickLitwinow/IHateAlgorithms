#include <iostream>
using namespace std;

int main () {
  unsigned short p;
  cin >> p;
  if (p % 2 == 0 && p != 2) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}