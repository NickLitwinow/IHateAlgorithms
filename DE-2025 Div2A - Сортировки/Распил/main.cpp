#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, B;
  cin >> n >> B;
  int a[101];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
    
  int even = 0, odd = 0;
  vector<int> v;
  for (int i = 0; i < n - 1; i++){
    if(a[i] % 2 == 0)
      even++;
    else
      odd++;
    if(even == odd){
      int c = abs(a[i] - a[i+1]);
      v.push_back(c);
    }
  }
  sort(v.begin(), v.end());
    
  int cnt = 0;
  for (int i = 0; i < (int)v.size(); i++){
    if(B >= v[i]){
      B -= v[i];
      cnt++;
    } else {
      break;
    }
  }
  
  cout << cnt;
  return 0;
}