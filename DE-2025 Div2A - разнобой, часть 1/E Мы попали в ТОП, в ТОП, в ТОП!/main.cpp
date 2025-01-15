#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, k, count = 0;
    vector<int> scores;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        scores.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        if (scores[i] >= scores[k - 1] && scores[i] > 0) {
            count++;
        }
    }
    cout << count;
    return 0;
}