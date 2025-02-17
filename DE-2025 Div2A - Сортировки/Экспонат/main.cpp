#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  long long total = 0;
  int H = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    total += a[i];
    if(a[i] > H) H = a[i];
  }
  sort(a.begin(), a.end());
  int M = 0;
  for (int i = 0; i < n; i++){
    if(a[i] >= M + 1){
      M++;
    }
  }
  long long ans = total - (n + H - M);
  cout << ans;
  return 0;
}