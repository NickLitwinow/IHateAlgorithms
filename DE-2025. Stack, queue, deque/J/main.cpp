#include <cstdio>

const int MAXN = 150000;
int qv[MAXN], qi[MAXN];
int ans[MAXN];

int main(){
    int N, K;
    if (scanf("%d %d", &N, &K) != 2) return 0;

    int head = 0, tail = 0, cnt = 0;
    for(int i = 0; i < N; ++i){
        int x;
        scanf("%d", &x);
        while(tail > head && qv[tail-1] > x)
            --tail;
        qv[tail] = x;
        qi[tail] = i;
        ++tail;
        if (qi[head] <= i - K)
            ++head;
        if (i >= K - 1)
            ans[cnt++] = qv[head];
    }

    for(int i = 0; i < cnt; ++i)
        printf("%d\n", ans[i]);

    return 0;
}