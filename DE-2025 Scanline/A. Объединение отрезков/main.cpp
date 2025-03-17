#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
  int L, R;
};

bool cmp(const Interval &a, const Interval &b) {
  if (a.L == b.L) {
    return a.R < b.R;
  }
  return a.L < b.L;
}

int main () {
  int n;
  cin >> n;
  vector<Interval> intervals(n);

  for (int i = 0; i < n; i++) {
    cin >> intervals[i].L >> intervals[i].R;
  }

  sort(intervals.begin(), intervals.end(), cmp);

  vector<Interval> merged;
  merged.push_back(intervals[0]);

  for (int i = 1; i < n; i++) {
    if (intervals[i].L <= merged.back().R) {
      if(intervals[i].R > merged.back().R)
        merged.back().R = intervals[i].R;
    } else {
      merged.push_back(intervals[i]);
    }
  }

  cout << merged.size() << "\n";
  for (int i = 0; i < merged.size(); i++) {
    cout << merged[i].L << " " << merged[i].R << "\n";
  }
  return 0;
}
