#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
  string s;
  int n;
  cin>>s>>n;
  vector<string> words(n);
  for(int i=0;i<n;i++){
    cin>>words[i];
  }
  for(int i=0;i<n;i++){
    if(words[i]==s){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(words[i][1]==s[0] && words[j][0]==s[1]){
        cout<<"YES"<<endl;
        return 0;
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}