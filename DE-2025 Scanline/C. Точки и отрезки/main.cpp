#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
  int n, m;
  cin >> n >> m;

  vector<int> lefts, rights;
  lefts.reserve(n);
  rights.reserve(n);

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int L = (a < b) ? a : b;
    int R = (a < b) ? b : a;
    lefts.push_back(L);
    rights.push_back(R);
  }

  sort(lefts.begin(), lefts.end());
  sort(rights.begin(), rights.end());

  vector<int> points(m), ans(m);
  for (int i = 0; i < m; i++) {
    cin >> points[i];
  }

  for (int i = 0; i < m; i++) {
    int x = points[i];
    int countL = upper_bound(lefts.begin(), lefts.end(), x) - lefts.begin();
    int countR = lower_bound(rights.begin(), rights.end(), x) - rights.begin();
    ans[i] = countL - countR;
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
