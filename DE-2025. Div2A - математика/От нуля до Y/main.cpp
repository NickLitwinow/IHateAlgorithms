#include <iostream>
#include <cmath>
using namespace std;

int main () {
  int t;
  cin>>t;
  while (t--) {
    long long x, y;
    cin>>x>>y;
    int operations = 0;
    for (long long p=9; p>=0; --p) {
      long long add = x * pow(10, p);
      if (add <= y) {
        long long times = y / add;
        operations += times;
        y -= times * add;
      }
    }
    operations += y;
    cout << operations << endl;
  }
  return 0;
}