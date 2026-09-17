#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d110

/* Min domination set of a tree */

// top-down DP 
// d1(r) : min cost with root;
// d01(r): without root but root is dominated;
// d00(r): without root and root is not necessarily dominated.

int n;
vector<int> w, d1, d01, d00;
vector<vector<int>> adj;

void read_input();
void dfs(int r, int p);


int main()
{
    read_input();
    dfs(1, 0); // parent of root(1) is set to 0 (dummy)
    printf("%d", min(d1[1], d01[1]));
}

void read_input()
{
    scanf("%d", &n);

    w.resize(n + 1);
    d1.resize(n + 1);
    d01.resize(n + 1);
    d00.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w[i]);
    }

    int u, v;

    for (int i = 1; i < n; ++i) {
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int r, int p)
{
    d1[r] = w[r];
    d01[r] = INT_MAX;
    d00[r] = 0;

    for (int &v : adj[r]) {

        if (v == p) continue;
        
        dfs(v, r);
        
        d1[r]  += min(d00[v], d1[v]);
        d00[r] += min(d1[v], d01[v]);
        d01[r]  = min(d01[r], d1[v] - d01[v]);
    }

    d01[r] = d00[r] + max(0, d01[r]);
}