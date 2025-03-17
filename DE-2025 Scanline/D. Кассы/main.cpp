#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
  int N;
  cin >> N;

  const int DAY = 86400;
  vector<int> diff(DAY + 1, 0);

  for (int i = 0; i < N; i++) {
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    int openTime = h1 * 3600 + m1 * 60 + s1;
    int closeTime = h2 * 3600 + m2 * 60 + s2;

    if (openTime == closeTime) {
      diff[0] += 1;
      diff[DAY] -= 1;
    } else if (openTime < closeTime) {
      diff[openTime] += 1;
      diff[closeTime] -= 1;
    } else {
      diff[openTime] += 1;
      diff[DAY] -= 1;
      diff[0] += 1;
      diff[closeTime] -= 1;
    }
  }

  int current = 0;
  long long total = 0;
  for (int t = 0; t < DAY; t++) {
    current += diff[t];
    if (current == N) {
      total++;
    }
  }
  cout << total << "\n";
  return 0;
}
