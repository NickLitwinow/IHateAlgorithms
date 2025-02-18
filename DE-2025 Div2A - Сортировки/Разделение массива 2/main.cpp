#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  long long base = 0;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    base += a[i];
  }
  
  if(k == 1){
    cout << base;
    return 0;
  }
  vector<long long> v;
  long long suf = 0;
  vector<long long> s(n);
  suf = 0;
  for (int i = n - 1; i >= 0; i--){
    suf += a[i];
    s[i] = suf;
  }
  
  for (int i = 0; i < n - 1; i++){
    v.push_back(s[i+1]);
  }
  sort(v.begin(), v.end());
  
  long long add = 0;
  int cnt = k - 1;
  for (int i = v.size() - 1; i >= 0 && cnt > 0; i--){
    add += v[i];
    cnt--;
  }
    
  cout << base + add;
  return 0;
}