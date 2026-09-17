#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d073

typedef long long LL;

int m, n;
vector<vector<LL>> table;
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
    table.resize(m + 1, vector<LL>(n + 1));
    dp.resize(n + 1, vector<LL>(n + 1));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%lld", &table[i][j]);
        }
    }
}

LL find_ans() 
{
    LL ans = 0;

    for (int i = 1; i <= m; ++i) {

        for (int j = 1; j <= n; ++j) {
            table[i][j] += table[i][j - 1];
        }
        
        for (int j = 1; j <= n; ++j) {
            table[i][j] += table[i - 1][j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k < j; ++k) {
                ans = max(ans, table[i][j] - table[i][k] + dp[k][j]);
                dp[k][j] = max(dp[k][j], table[i][k] - table[i][j]);
            }
        }
    }

    return ans;
}