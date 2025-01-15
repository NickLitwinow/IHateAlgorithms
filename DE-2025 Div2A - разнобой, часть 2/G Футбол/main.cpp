#include <iostream>
using namespace std;

int main () {
  string s;
  cin>>s;
  int counter = 1;
  for (int i = 0; i < s.length(); i++) {
    if (i > 0 && s[i] == s[i-1]) {
      counter++;
    } else {
      counter = 1;
    }
    if (counter >= 7) {
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}