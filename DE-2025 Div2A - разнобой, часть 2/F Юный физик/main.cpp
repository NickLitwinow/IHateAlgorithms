#include <iostream>
using namespace std;

int main () {
  int n, res_x = 0, res_y = 0, res_z = 0;
  cin>>n;
  for (int i=0;i<n;i++){
    int x, y, z;
    cin>>x>>y>>z;
    res_x += x;
    res_y += y;
    res_z += z;
  }
  if (res_x == 0 && res_y == 0 && res_z == 0) {
    cout<<"YES"<<endl;
  } else {
    cout<<"NO"<<endl;
  }
  return 0;
}