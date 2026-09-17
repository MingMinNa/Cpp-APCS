#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d100

int n, m, T;
vector<char> color;
vector<vector<int>> adj;

void read_input();
bool check();
bool bfs(int idx);


int main() 
{
    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        read_input();
        printf(check() ? "yes\n" : "no\n");
    }
}

void read_input() 
{
    scanf("%d %d", &n, &m);
    adj.assign(n, vector<int>());
    color.assign(n, -1);

    int u, v;

    for (int i = 0; i < m; ++i) {
        
        scanf("%d %d", &u, &v);

        if (u == v) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool check() 
{
    for (int i = 0; i < n; ++i) {
        if (color[i] != -1) continue;
        if (!bfs(i))        return false;
    }

    return true;
}

bool bfs(int idx) 
{
    queue<pair<int, int>> q;
    
    q.push({idx, 1});
    color[idx] = 1; 

    while (!q.empty()) {
        
        auto [i, c] = q.front(); q.pop();

        for (const auto &e : adj[i]) {

            if (color[i] == color[e]) {
                return false;
            }

            if (color[e] == -1) {
                q.push({e, !c});
                color[e] = !c;
                continue;
            }
        }
    }

    return true;
}