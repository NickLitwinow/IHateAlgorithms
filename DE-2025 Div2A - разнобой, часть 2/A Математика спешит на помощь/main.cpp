#include <iostream>
#include <vector>
using namespace std;

int main () {
  string s;
  getline(cin, s);
  vector<int> nums;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] != '+') {
      nums.push_back(s[i] - '0');
    }
  }

  sort(nums.begin(), nums.end());

  string res;
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0) {
      res += '+';
    }
    res += to_string(nums[i]);
  }

  cout << res << endl;
  return 0;
}