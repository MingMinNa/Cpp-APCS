#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d015

typedef long long LL;

int m, n, K, t;
LL ans = 0;
unordered_map<int, int> counts;

void read_input();


int main() 
{
    read_input();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d %d", &m, &n, &K);

    for (int i = 0; i < m; ++i) {
        scanf("%d", &t);
        counts[K - t] ++;
    }
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        ans += counts[t];
    }
}