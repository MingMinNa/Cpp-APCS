#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d084

typedef long long LL;

int n, K;
vector<LL> revenue;
vector<LL> dp;

void read_input();
LL find_ans();


int main() 
{
    read_input();
    printf("%lld\n", find_ans());
}

void read_input() 
{
    scanf("%d %d", &n, &K);
    revenue.resize(n);
    dp.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &revenue[i]);
    }
}

LL find_ans() 
{
    dp[0] = revenue[0];
    
    for (int i = 1; i <= K; ++i) {
        dp[i] = max(dp[i - 1], revenue[i]);
    }

    for (int i = K + 1; i < n; ++i) {
        dp[i] = max(
            dp[i - K - 1] + revenue[i],
            dp[i - 1]
        );
    }

    return dp[n - 1];
}