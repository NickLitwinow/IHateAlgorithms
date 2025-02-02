#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      v[i]=i+1;
    }
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      cout << i+1 << " ";
    }
    cout << endl;
  }
  return 0;
}