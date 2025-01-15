#include <iostream>
using namespace std;

int main () {
    long long n, m, a, tiles_l, tiles_w;
    cin >> n >> m >> a;
    tiles_l = (n + a - 1) / a;
    tiles_w = (m + a - 1) / a;
    cout << tiles_l * tiles_w;
    return 0;
}