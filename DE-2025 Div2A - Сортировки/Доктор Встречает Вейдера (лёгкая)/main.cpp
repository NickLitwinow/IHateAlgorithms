#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int s, b;
  cin >> s >> b;
  vector<int> a(s);
  for (int i = 0; i < s; i++) {
    cin >> a[i];
  }
  
  vector< pair<int, int> > bases(b);
  for (int i = 0; i < b; i++) {
    cin >> bases[i].first >> bases[i].second;
  }
  sort(bases.begin(), bases.end());
    
  vector<long long> a2(b);
  a2[0] = bases[0].second;
  for (int i = 1; i < b; i++) {
    a2[i] = a2[i - 1] + bases[i].second;
  }

  for (int i = 0; i < s; i++) {
    int attack = a[i];
    int lo = 0, hi = b - 1, pos = -1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (bases[mid].first <= attack) {
        pos = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    if (pos == -1)
      cout << 0 << " ";
    else
      cout << a2[pos] << " ";
  }
  return 0;
}