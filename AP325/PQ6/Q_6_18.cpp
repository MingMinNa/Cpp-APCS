#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d086

typedef long long LL;

int n;
vector<LL> chain;
vector<vector<LL>> dp;

void read_input();
LL min_mat_mul(int left, int right);


int main() 
{
    read_input();
    printf("%lld\n", min_mat_mul(0, n));
}

void read_input() 
{
    scanf("%d", &n);
    chain.resize(n + 1);
    dp.resize(n + 1, vector<LL>(n + 1));

    for (int i = 0; i <= n; ++i) {
        scanf("%lld", &chain[i]);
    }
}

LL min_mat_mul(int left, int right) 
{
    if (left + 1 >= right)   return 0ll;
    if (dp[left][right] > 0) return dp[left][right];

    LL ret = LLONG_MAX;

    for (int i = left + 1; i < right; ++i) {
        ret = min(
            ret, 
            chain[left] * chain[i] * chain[right] 
                + min_mat_mul(left, i)
                + min_mat_mul(i, right)
        );
    }
    
    dp[left][right] = ret;
    return ret;
}