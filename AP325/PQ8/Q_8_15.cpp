#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d115

typedef long long LL;

int n;
LL edge_sum = 0, diameter = 0;
vector<char> visited;
vector<vector<pair<int, LL>>> adj;

void read_input();
LL dfs(int u);


int main() 
{
    read_input();
    dfs(0);
    printf("%lld\n", edge_sum * 2 - diameter);
}

void read_input() 
{
    scanf("%d", &n);
    adj.resize(n);
    visited.resize(n);

    int u, v, t;
    
    for (int i = 1; i < n; ++i) {
        
        scanf("%d %d %d", &u, &v, &t);

        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
}

LL dfs(int u) 
{
    visited[u] = 1;
    LL max_dist[2] = {0, 0};
    
    for (auto [v, l] : adj[u]) {

        if (visited[v]) continue;
        
        LL path_dist = dfs(v) + l;
        edge_sum += l;
        
        if (path_dist >= max_dist[0]) {
            max_dist[1] = max_dist[0];
            max_dist[0] = path_dist;
        }
        else if (path_dist > max_dist[1]) {
            max_dist[1] = path_dist;
        }
    }

    diameter = max(diameter, max_dist[0] + max_dist[1]);
    return max_dist[0];
}