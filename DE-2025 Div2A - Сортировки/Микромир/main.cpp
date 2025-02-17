#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, K;
  cin >> n >> K;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
 
  int res = 0;
  int i = 0;
  while(i < n){
    int val = a[i];
    int cnt = 0;
    while(i < n && a[i] == val){
      cnt++;
      i++;
    }

    if(i == n){
      res += cnt;
    } else {
      int nextVal = a[i];
      if (nextVal - val <= K) {
        res += 0;
      } else {
        res += cnt;
      }
    }
  }
  cout << res;
  return 0;
}