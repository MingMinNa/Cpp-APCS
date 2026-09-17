#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d081

typedef long long LL;

int n, m;
vector<int> vec;
vector<int> dp;

void read_input();
LL recursive(int val);


int main()
{
    read_input();
    printf("%lld", recursive(m));
}

void read_input()
{
    scanf("%d", &n);
    m = (1 << n) - 1;
    
    vec.resize(m + 1);
    dp.resize(m + 1, -1);

    for (int i = 0; i <= m; ++i) {
        scanf("%d", &vec[i]);
    }

    dp[0] = vec[0];
}

LL recursive(int val)
{
    if (dp[val] >= 0)
        return dp[val];

    LL ret = 0;
    
    for (int i = 0; i < n; ++i) {
        if ((1 << i) & val) {
            ret = max(ret, recursive(val - (1 << i)));
        }
    }

    ret += vec[val];
    return dp[val] = ret;
}