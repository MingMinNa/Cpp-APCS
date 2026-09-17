#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d076

#define MOD_P(x) ((x) % P)

typedef long long LL;

const LL P = 1e9 + 9;

int n;
vector<LL> dp;

LL catalan_num(int n);
void read_input();


int main()
{
    read_input();
    printf("%lld", catalan_num(n));
}

void read_input() 
{
    scanf("%d", &n);
    dp.resize(n + 1);
    dp[0] = 1;
}

LL catalan_num(int n)
{
    if (dp[n] > 0) return dp[n];

    LL ret = 0;
    
    for (int i = 0; i <= n - 1; ++i) {
        ret = MOD_P(MOD_P(catalan_num(i) * catalan_num(n - 1 - i)) + ret);
    }

    dp[n] = ret;
    return ret;
}