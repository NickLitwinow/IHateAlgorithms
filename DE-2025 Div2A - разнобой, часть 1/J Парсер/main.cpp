#include <iostream>
using namespace std;

int main () {
  string a, result, vowels = "aoyeuiAOYEUI";
  getline(cin, a);
  for (int i = 0; i < a.length(); i++) {
    if (vowels.find(a[i]) == string::npos) {
      a[i] = tolower(a[i]);
      result += '.';
      result += a[i];
    }
  }
  cout << result << endl;
  return 0;
}