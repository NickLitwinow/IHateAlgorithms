#include <iostream>
using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 2050 != 0) {
      cout << -1 << endl;
      continue;
    }
    long long quotient = n / 2050;
    long long sum_digits = 0;
    while (quotient > 0) {
      sum_digits += quotient % 10;
      quotient /= 10;
    }
    cout << sum_digits << endl;
  }
  return 0;
}