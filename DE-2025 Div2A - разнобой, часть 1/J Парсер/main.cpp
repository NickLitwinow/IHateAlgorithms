#include <iostream>
using namespace std;

int main () {
  string a, result;
  getline(cin, a);
  for (int i = 0; i < a.length(); i++) {
    a[i] = tolower(a[i]);
    if (a[i] != 'a' && a[i] != 'o' && a[i] != 'y' && a[i] != 'e' && a[i] != 'u' && a[i] != 'i') {
      result += '.';
      result += a[i];
    }
  }
  cout << result << endl;
  return 0;
}