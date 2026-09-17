#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d095

int n, m, s, t;
vector<int> dist, in_deg, min_ans, max_ans;
vector<vector<pair<int, int>>> adj;

void read_input();
void bfs();


int main()
{
    read_input();
    bfs();

    if (min_ans[t] == INT_MAX) printf("No path\nNo path\n");
    else                       printf("%d\n%d\n", min_ans[t], max_ans[t]);
}

void read_input() 
{
    scanf("%d %d", &n, &m); 
    scanf("%d %d", &s, &t);

    adj.resize(n);
    in_deg.resize(n);
    min_ans.resize(n, INT_MAX);
    max_ans.resize(n, INT_MIN);

    int from, to, w;   

    for (int i = 0; i < m; ++i) {
        
        scanf("%d %d %d", &from, &to, &w);

        adj[from].push_back({to, w});
        in_deg[to] ++;
    }
}

void bfs()
{
    queue<int> q;
    min_ans[s] = max_ans[s] = 0;

    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {

        int v = q.front(); q.pop();
        
        for (auto &e: adj[v]) { 
            
            // path exists 
            if (min_ans[v] < INT_MAX) { 
                min_ans[e.first] = min(min_ans[e.first], min_ans[v] + e.second); 
                max_ans[e.first] = max(max_ans[e.first], max_ans[v] + e.second); 
            } 

            in_deg[e.first] --;
            
            if (in_deg[e.first] == 0) {
                q.push(e.first); 
            }
        } 
    }
}   