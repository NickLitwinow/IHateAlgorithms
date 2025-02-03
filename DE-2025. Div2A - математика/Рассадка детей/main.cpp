#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    vector<int> v;
    int num = 2 * n;
    while (v.size() < n) {
      v.push_back(num);
      num += 2;
    }
    for (int i=0; i<n; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
  return 0;
}