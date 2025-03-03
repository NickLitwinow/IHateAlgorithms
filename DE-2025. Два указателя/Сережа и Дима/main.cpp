#include <iostream>
#include <string>
using namespace std;

int main () {
  int n;
  cin >> n;
  int cards[1001];
  for (int i = 0; i < n; i++){
    cin >> cards[i];
  }

  int left = 0, right = n - 1;
  int scoreS = 0, scoreD = 0;
  bool turnS = true;

  while (left <= right) {
    if (cards[left] > cards[right]) {
      if (turnS)
        scoreS += cards[left];
      else
        scoreD += cards[left];
      left++;
    } else {
      if (turnS)
        scoreS += cards[right];
      else
        scoreD += cards[right];
      right--;
    }
    turnS = !turnS;
  }

  cout << scoreS << " " << scoreD;
  return 0;
}
