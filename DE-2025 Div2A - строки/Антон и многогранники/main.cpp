#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main () {
  int n, result = 0;
  cin>>n;
  unordered_map<string, int> map;
  map["Tetrahedron"] = 4;
  map["Cube"] = 6;
  map["Octahedron"] = 8;
  map["Dodecahedron"] = 12;
  map["Icosahedron"] = 20;
  string s;
  for (int i = 0; i < n; i++) {
    cin>>s;
    result += map[s];
  }
  cout<<result<<endl;
  return 0;
}