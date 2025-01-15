#include <iostream>
using namespace std;

int main () {
  string s, res;
  int u = 0, l = 0;
  cin>>s;

  for(int i=0;i<s.length();i++){
    if ('A' <= s[i] && s[i] <= 'Z') {
      u++;
    } else if ('a' <= s[i] && s[i] <= 'z') {
      l++;
    }
  }

  if (u>l) {
    for (int i=0;i<s.length();i++){
      res += toupper(s[i]);
    }
  } else {
    for (int i=0;i<s.length();i++){
      res += tolower(s[i]);
    }
  }
  cout<<res<<endl;
  return 0;
}