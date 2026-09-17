#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d069

typedef long long LL;

int m, n;
vector<vector<LL>> dp;

void read_input();
LL find_ans();


int main()
{
    read_input();
    printf("%lld", find_ans());
}

void read_input()
{
    scanf("%d %d", &m, &n);
    dp.resize(m, vector<LL>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lld", &dp[i][j]);
        }
    }
}

LL find_ans()
{
    for (int i = 1; i < n; ++i)
        dp[0][i] += dp[0][i - 1];

    for (int i = 1; i < m; ++i)
        dp[i][0] += dp[i - 1][0];

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1];
}