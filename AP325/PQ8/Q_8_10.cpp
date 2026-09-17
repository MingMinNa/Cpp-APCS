#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d113
/* Minimum vertex cover */

typedef long long LL;

int n, ans = 0;
vector<int> parent;
vector<vector<int>> children;
vector<pair<int, int>> dp;

void read_input();
void dfs(int u);


int main() 
{
    read_input();
    dfs(0);
    printf("%d", min(dp[0].first, dp[0].second));
}

void read_input() 
{
    scanf("%d", &n);
    
    parent.resize(n);
    children.resize(n);
    dp.resize(n);

    for (int i = 1; i < n; ++i) {
        scanf("%d", &parent[i]);
        children[parent[i]].push_back(i);
    }
}

void dfs(int u) 
{
    dp[u].first = 0;
    dp[u].second = 1;

    for (const auto &v: children[u]) {
        dfs(v);
        dp[u].first += dp[v].second;
        dp[u].second += min(dp[v].first, dp[v].second);
    }
}