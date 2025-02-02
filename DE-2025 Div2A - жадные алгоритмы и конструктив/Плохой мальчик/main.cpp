#include <iostream>
#include <cmath>
using namespace std;

long long distance(int x1, int y1, int x2, int y2, int i, int j) {
  return abs(i - x1) + abs(j - y1) + abs(x1 - x2) + abs(y1 - y2) + abs(x2 - i) + abs(y2 - j);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, i, j;
    cin>>n>>m>>i>>j;
    int corners[4][2] = {{1, 1}, {1, m}, {n, 1}, {n, m}};

    int x1 = 1, y1 = 1, x2 = n, y2 = m;
    long long d1 = distance(x1, y1, x2, y2, i, j);

    int alt_x1 = 1, alt_y1 = m, alt_x2 = n, alt_y2 = 1;
    long long d2 = distance(alt_x1, alt_y1, alt_x2, alt_y2, i, j);

    if (d2 > d1) {
      cout<<alt_x1<<" "<<alt_y1<<" "<<alt_x2<<" "<<alt_y2<<endl;
    } else {
      cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<< endl;
    }
  }
  return 0;
}
