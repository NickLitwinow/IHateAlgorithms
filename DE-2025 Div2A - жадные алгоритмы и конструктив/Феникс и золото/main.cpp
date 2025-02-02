#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i=0; i<n; i++) {
      cin >> w[i];
    }
    sort(w.begin(), w.end());
    int sum = 0;
    bool possible = true;
    for (int i=0; i<n; i++) {
      sum += w[i];
      if (sum == x) {
        if (i == n-1) {
          possible = false;
          break;
        } else {
          swap(w[i], w[n - 1]);
          break;
        }
      }
    }

    if (!possible) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i=0; i<n; i++) {
        cout << w[i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
