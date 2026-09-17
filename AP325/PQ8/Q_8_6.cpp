#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d108

typedef long long LL;

int n;
LL ans = 0;
vector<vector<pair<LL, int>>> adj;

void read_input();
pair<LL, int> search(int u);


int main() 
{
    read_input();
    search(0);
    printf("%lld\n", ans);
}

void read_input() 
{
    scanf("%d", &n);
    adj.resize(n);
    vector<int> parent(n);
    vector<LL> dist(n);

    for (int i = 1; i < n; ++i) {
        scanf("%d", &parent[i]);
    }

    for (int i = 1; i < n; ++i) {
        scanf("%lld", &dist[i]);
    }

    for (int i = 1; i < n; ++i) {
        adj[parent[i] - 1].push_back({dist[i], i});
    }
}

pair<LL, int> search(int u) 
{
    if (adj[u].size() == 0) 
        return {0ll, 1};

    int size = adj[u].size();
    vector<pair<LL, int>> sub_tree;
    pair<LL, int> ret = {0, 1};

    for (int i = 0; i < size; ++i) {

        int child = adj[u][i].second;
        LL length = adj[u][i].first;

        pair<LL, int> sub_ret = search(child);
        sub_ret.first += sub_ret.second * length;

        sub_tree.push_back(sub_ret);
        ret.first  += sub_ret.first;
        ret.second += sub_ret.second;
    }

    int total_count = ret.second;
    
    for (int i = 0; i < size; ++i) {
        ans += (2ll * sub_tree[i].first * (total_count - sub_tree[i].second));
    }
    
    return ret;
}