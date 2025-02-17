#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  for (int i = 0; i < n; i++){
    cin >> B[i];
  }

  sort(A.begin(), A.end(), greater<int>());
  sort(B.begin(), B.end(), greater<int>());
    
  int i = 0, j = 0;
  long long res = 0;
  bool At = true;

  while(i < n || j < n){
    if(At){
      if(i < n && (j >= n || A[i] >= B[j])){
        res += A[i];
        i++;
      } else if(j < n){
        j++;
      }
      At = false;
    } else {
      if(j < n && (i >= n || B[j] >= A[i])){
        res -= B[j];
        j++;
      } else if(i < n){
        i++;
      }
      At = true;
    }
  }

  cout << res;
  return 0;
}