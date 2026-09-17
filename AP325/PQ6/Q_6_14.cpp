#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d085

typedef long long LL;

int n, K;
vector<LL> p;
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
    scanf("%d %d", &n, &K);
    p.resize(n);
    dp.resize(K + 1, vector<LL>(n));

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &p[i]);
    }
}

LL find_ans() 
{
    for (int i = 1; i <= K; ++i) {

        LL max_val = dp[i - 1][0] - p[0];

        for (int j = 1; j < n; ++j) {

            dp[i][j] = max(
                dp[i][j - 1],
                max_val + p[j] // sell on day j (buy was at some earlier day)
            );
        
            max_val = max(
                max_val,
                dp[i - 1][j] - p[j] // buy on day j, with (i-1) trades already completed
            );
        }
    }

    return dp[K][n - 1];
}