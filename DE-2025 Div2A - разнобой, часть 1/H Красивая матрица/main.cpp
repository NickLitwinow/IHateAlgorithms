#include <iostream>
#include <vector>
using namespace std;

int main () {
    int row = 0, col = 0;
    bool found = false;
    for (int i = 1; i <= 5 && !found; i++) {
      for (int j = 1; j <= 5 && !found; j++) {
        int temp;
        cin >> temp;
        if (temp == 1) {
          row = i;
          col = j;
          found = true;
        }
      }
    }

    cout << abs(row - 3) + abs(col - 3) << endl;
    return 0;
}