#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d052

typedef long long LL;

int n;
LL ans = 0;

void read_input();


int main()
{
    read_input();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d", &n);

    int t;
    LL min_prefix = 0, prefix = 0;

    for (int i = 0; i < n; ++i) {
        
        scanf("%d", &t);

        prefix += t;
        min_prefix = min(min_prefix, prefix);
        ans = max(ans, prefix - min_prefix);
    }
}