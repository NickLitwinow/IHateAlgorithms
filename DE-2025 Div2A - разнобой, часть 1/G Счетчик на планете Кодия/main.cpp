#include <iostream>
using namespace std;

int main () {
  int n, count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    if (temp == "++X" || temp == "X++") {
      count++;
    } else if (temp == "X--" || temp == "--X") {
      count--;
    }
  }
  cout << count << endl;
  return 0;
}