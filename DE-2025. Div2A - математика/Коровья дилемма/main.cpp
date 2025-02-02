#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main() {
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
      cin>>v[i];
    }
    set<int> areas;
    for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        int base = abs(v[j] - v[i]);
        int area = base;
        if (area > 0) {
          areas.insert(area);
        }
      }
    }
    cout << areas.size() << endl;
  }
  return 0;
}