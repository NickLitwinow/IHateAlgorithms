#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
  int L, R;
};


bool cmp(const Interval &a, const Interval &b) {
  if(a.L == b.L)
    return a.R < b.R;
  return a.L < b.L;
}

int main () {
  int M;
  cin >> M;

  vector<Interval> intervals;
  while (true) {
    int L, R;
    cin >> L >> R;
    if(L == 0 && R == 0) break;
    intervals.push_back({L, R});
  }

  sort(intervals.begin(), intervals.end(), cmp);

  vector<Interval> ans;
  int current = 0;
  int i = 0;
  int n = intervals.size();

  while(current < M) {
    int bestRight = current;
    Interval bestInterval = {0, 0};
    bool found = false;

    while(i < n && intervals[i].L <= current) {
      if(intervals[i].R > bestRight) {
        bestRight = intervals[i].R;
        bestInterval = intervals[i];
        found = true;
      }
      i++;
    }

    if(!found) {
      cout << "No solution" << "\n";
      return 0;
    }

    ans.push_back(bestInterval);
    current = bestRight;
  }

  cout << ans.size() << "\n";
  for (int j = 0; j < ans.size(); j++) {
    cout << ans[j].L << " " << ans[j].R << "\n";
  }
  return 0;
}
