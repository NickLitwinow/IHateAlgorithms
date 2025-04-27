#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
  int x, y1, y2, type;
};

bool cmpEvent(const Event &a, const Event &b) {
  return a.x < b.x;
}

int main () {
  int N;
  cin >> N;

  vector<Event> events;
  vector<int> ys;

  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2 || y1 == y2)
      continue;
    Event e;
    e.x = x1; e.y1 = y1; e.y2 = y2; e.type = 1;
    events.push_back(e);
    e.x = x2; e.y1 = y1; e.y2 = y2; e.type = -1;
    events.push_back(e);
    ys.push_back(y1);
    ys.push_back(y2);
  }

  if (events.empty()) {
    cout << 0 << "\n";
    return 0;
  }
  sort(events.begin(), events.end(), cmpEvent);
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());

  int m = ys.size();
  vector<int> cnt(m - 1, 0);

  long long area = 0;
  int lastX = events[0].x;
  int i = 0, E = events.size();

  while (i < E) {
    int curX = events[i].x;
    int dx = curX - lastX;
    if (dx > 0) {
      int unionY = 0;
      for (int j = 0; j < m - 1; j++) {
        if (cnt[j] > 0)
          unionY += ys[j + 1] - ys[j];
      }
      area += (long long)dx * unionY;
      lastX = curX;
    }
    while (i < E && events[i].x == curX) {
      int l = lower_bound(ys.begin(), ys.end(), events[i].y1) - ys.begin();
      int r = lower_bound(ys.begin(), ys.end(), events[i].y2) - ys.begin();
      for (int j = l; j < r; j++) {
         cnt[j] += events[i].type;
      }
      i++;
    }
  }

  cout << area << "\n";
  return 0;
}
