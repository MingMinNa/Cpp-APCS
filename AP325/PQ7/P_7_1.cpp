#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d090

int n, m, s, ans = 0, ans_dist = 0;
vector<vector<int>> adj;

void read_input();
void dfs();


int main()
{
    read_input();
    dfs();
    printf("%d\n%d", ans, ans_dist);
}

void read_input()
{
    scanf("%d %d", &n, &m);
    scanf("%d", &s);
    adj.resize(n);

    int from, to;

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &from, &to);
        adj[from].push_back(to);
    }
}

void dfs()
{
    queue<int> q;
    vector<int> dist(n);
    vector<char> visited(n, 0);

    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {

        int t = q.front(); 
        q.pop();

        ans ++;
        ans_dist += dist[t];

        for (auto &t2 : adj[t]) {
            if (visited[t2] == 0) {
                q.push(t2);
                visited[t2] = 1;
                dist[t2] = dist[t] + 1;
            }
        }
    }
    
    // The starting point is not included.
    ans --;
}