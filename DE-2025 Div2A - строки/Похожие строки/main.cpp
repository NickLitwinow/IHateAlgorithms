#include <iostream>
#include <string>
using namespace std;

int main () {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s, w="";
    cin>>s;
    for(int i=0;i<n-1;i++){
      w+=s[i*2];
    }
    w+=s[s.size()-1];
    cout<<w<<endl;
  }
  return 0;
}