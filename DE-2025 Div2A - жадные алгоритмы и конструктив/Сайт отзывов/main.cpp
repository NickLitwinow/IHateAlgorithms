#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> users(n);
    for (int i=0; i<n; i++) {
      cin>>users[i];
    }
    int likes = 0, dislikes = 0;
    int type1 = 0, type2 = 0, type3 = 0;
    for (int i=0; i<n; i++) {
      if (users[i] == 1) {
        type1++;
      } else if (users[i] == 2) {
        type2++;
      } else {
        type3++;
      }
    }
    likes += type1;
    likes += min(type3, max(0, likes - dislikes + type3));
    cout << likes << endl;
  }
  return 0;
}