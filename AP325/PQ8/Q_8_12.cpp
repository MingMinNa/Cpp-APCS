#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d114

typedef long long LL;

int n;
LL ans = 0;
vector<int> revenue;
vector<char> visited;
vector<vector<int>> adj;

void read_input();
LL dfs(int u);


int main() 
{
    read_input();
    dfs(0);
    printf("%lld", ans);
}

void read_input() 
{
    scanf("%d", &n);

    adj.resize(n);
    revenue.resize(n);
    visited.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &revenue[i]);
    }

    int u, v;

    for (int i = 1; i < n; ++i) {

        scanf("%d %d", &u, &v);
        
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
}

LL dfs(int u) 
{
    LL ret = revenue[u];
    visited[u] = 1;

    for (const auto &v : adj[u]) {

        if (visited[v]) continue;

        LL t = dfs(v);
        if (t > 0) ret += t;
    }

    ans = max(ans, ret);
    visited[u] = 0;
    return ret;
}