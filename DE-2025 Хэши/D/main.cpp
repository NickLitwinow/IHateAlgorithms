#include <cstdio>
#include <cstring>

static unsigned char dp[5002][5002];
static int P[5002][5002];
static char s[5005];

// ну я не знаю куда еще быстрее
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1, j = len; j <= n; ++i, ++j) {
            if (s[i] == s[j] && (len == 2 || dp[i+1][j-1])) {
                dp[i][j] = 1;
            }
        }
    }

    for (int j = 0; j <= n; ++j) {
        P[0][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int rowSum = 0;
        P[i][0] = 0;
        for (int j = 1; j <= n; ++j) {
            rowSum += dp[i][j];
            P[i][j] = P[i-1][j] + rowSum;
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = P[r][r] - P[l-1][r] - P[r][l-1] + P[l-1][l-1];
        printf("%d\n", ans);
    }

    return 0;
}
