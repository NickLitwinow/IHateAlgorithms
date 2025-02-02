#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
      cin>>v[i];
    }
    for (int i=0; i<n-1 && k>0; i++) {
      int step = min(v[i], k);
      v[i] -= step;
      v[n - 1] += step;
      k -= step;
    }
    for (int i=0; i<n; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
  return 0;
}