#include <iostream>
using namespace std;

int main () {
  string t;
  int n, ab_counter = 0, ba_counter = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    for (int j = 1; j < t.length(); j++) {
      if (t[j] == 'b' && t[j - 1] == 'a') {
        ab_counter++;
      }
      if (t[j] == 'a' && t[j - 1] == 'b') {
        ba_counter++;
      }
    }
    if (ab_counter > ba_counter || ba_counter > ab_counter) {
      for (int j = 1; j < t.length(); j++) {
        if (t[j] == 'b' && t[j - 1] == 'a') {
          ab_counter++;
        }
        if (t[j] == 'a' && t[j - 1] == 'b') {
          ba_counter++;
        }
      }
    }
    cout << t << endl;
    ab_counter = 0;
    ba_counter = 0;
  }
  return 0;
}