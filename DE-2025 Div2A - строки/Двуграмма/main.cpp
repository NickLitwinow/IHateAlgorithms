#include <iostream>
#include <string>
#include <map>
using namespace std;

int main () {
  int n, count = 0;
  cin>>n;
  string s, max;
  cin>>s;
  map<string,int> m;
  for(int i=0;i<n-1;i++){
    string temp = s.substr(i,2);
    m[temp]++;
  }
  for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
    if(it->second>count){
      count = it->second;
      max = it->first;
    }
  }
  cout<<max<<endl;
  return 0;
}