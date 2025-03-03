#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Point {
  int x, y;
};

int main () {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int tx, ty;
  cin >> tx >> ty;

  vector<Point> p(n+1);
  p[0].x = 0;
  p[0].y = 0;
  for (int i = 0; i < n; i++){
    int dx = 0, dy = 0;
    if(s[i]=='U') dy = 1;
    else if(s[i]=='D') dy = -1;
    else if(s[i]=='L') dx = -1;
    else if(s[i]=='R') dx = 1;
    p[i+1].x = p[i].x + dx;
    p[i+1].y = p[i].y + dy;
  }

  int diffX = tx - p[n].x;
  int diffY = ty - p[n].y;

  if(diffX == 0 && diffY == 0){
    cout << 0;
    return 0;
  }

  int lo = 1, hi = n, ans = -1;
  while(lo <= hi){
    int mid = (lo + hi) / 2;
    bool ok = false;
    for (int l = 0; l <= n - mid; l++){
      int r = l + mid - 1;
      int seg_dx = p[r+1].x - p[l].x;
      int seg_dy = p[r+1].y - p[l].y;
      int req_x = diffX + seg_dx;
      int req_y = diffY + seg_dy;
      int man = abs(req_x) + abs(req_y);
      if(man <= mid && ((mid - man) % 2 == 0)){
        ok = true;
        break;
      }
    }
    if(ok){
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans;
  return 0;
}
