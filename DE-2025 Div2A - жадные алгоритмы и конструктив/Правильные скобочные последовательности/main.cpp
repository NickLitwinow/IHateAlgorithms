#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i=1; i<=n; ++i) {
      string result;
      for (int j=0; j<i; ++j) {
        result += "(";
      }
      for (int j=0; j<i; ++j) {
        result += ")";
      }
      for (int j=0; j<n-i; ++j) {
        result = "()" + result;
      }
      cout << result << endl;
    }
  }
  return 0;
}