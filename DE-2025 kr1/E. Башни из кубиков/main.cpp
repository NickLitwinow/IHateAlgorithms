#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());

    int res = 1, temp = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i - 1]) {
            temp++;
        } else {
            res = max(res, temp);
            temp = 1;
        }
    }
    cout << max(res, temp);

    return 0;
}