#include <iostream>
using namespace std;

bool isPalindrom(string s){
  for(int i = 0; i < s.size()/2; i++){
    if(s[i] != s[s.size()-i-1]) return false;
  }
  return true;
}

int main () {
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    if(!isPalindrom(s)){
      cout << s << endl;
      continue;
    }
    bool check = true;
    int n = s.size();
    for(int i = 0; i < n - 1; i++){
      if(s[i] != s[i+1]){
        check = false;
        swap(s[i], s[i+1]);
        cout << s << endl;
        break;
      }
    }
    if(check){
      cout << -1 << endl;
    }
  }
  return 0;
}