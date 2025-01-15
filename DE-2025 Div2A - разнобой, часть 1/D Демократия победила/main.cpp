#include <iostream>
using namespace std;

int main () {
    unsigned int n, count = 0;
    cin >> n;
    for (unsigned int i = 0; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      if (a + b + c >= 2) {
        count += 1;
      }
    }
    cout << count;
    return 0;
}