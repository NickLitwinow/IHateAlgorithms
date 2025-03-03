#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main () {
  int n, m;
  long long k;
  cin >> n >> m >> k;
  vector<vector<int> > droid(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> droid[i][j];
    }
  }

  int l = 0, bestLen = 0;
  vector<int> bestShots(m, 0);
  vector< deque<int> > dq(m);

  for (int r = 0; r < n; r++){
    for (int j = 0; j < m; j++){
      while (!dq[j].empty() && droid[dq[j].back()][j] <= droid[r][j])
        dq[j].pop_back();
      dq[j].push_back(r);
    }

    while (l <= r) {
      long long sum = 0;
      for (int j = 0; j < m; j++){
        sum += droid[dq[j].front()][j];
      }
      if (sum <= k) break;
      for (int j = 0; j < m; j++){
        if (!dq[j].empty() && dq[j].front() == l)
          dq[j].pop_front();
      }
      l++;
    }

    long long sum = 0;
    for (int j = 0; j < m; j++){
      sum += droid[dq[j].front()][j];
    }
    if (sum <= k) {
      int curLen = r - l + 1;
      if (curLen > bestLen) {
        bestLen = curLen;
        for (int j = 0; j < m; j++){
          bestShots[j] = droid[dq[j].front()][j];
        }
      }
    }
  }

  for (int j = 0; j < m; j++){
    cout << bestShots[j] << " ";
  }
  return 0;
}
