#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--) {
    int x;
    cin>>x;
    string s = to_string(x);
    int d = s[0] - '0';
    int length = s.length();
    int result = (d - 1) * 10 + (length * (length + 1)) / 2;
    cout << result << endl;
  }
  return 0;
}