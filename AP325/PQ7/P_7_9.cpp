#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d096

int n, m, ans_count = 0, max_ans = 0;
vector<int> min_dist;
vector<vector<pair<int, int>>> adj;

void read_input();
void dijkstra();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%d\n%d", max_ans, ans_count);
}

void read_input()
{
    scanf("%d %d", &n, &m);
    min_dist.resize(n, INT_MAX);
    adj.resize(n);

    int from, to, w;

    for (int i = 0; i < m; ++i) {

        scanf("%d %d %d", &from, &to, &w);

        adj[from].push_back({to, w});
        adj[to].push_back({from, w});
    }
}

void dijkstra()
{
    vector<char> visited(n, 0);
    
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
    > pq; // first: distance, second: to

    min_dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {

        auto t = pq.top(); pq.pop();
        
        if (visited[t.second]) continue;
        
        visited[t.second] = 1;

        // t.first: distance, t.second: to
        // e.first: to,       e.second: weight

        for (auto &e : adj[t.second]) {
            
            if (visited[e.first] == 1 || e.second + t.first > min_dist[e.first]) 
                continue;
            
            min_dist[e.first] = e.second + t.first;
            pq.push({e.second + t.first, e.first});
        }
    }
}

void find_ans()
{
    dijkstra();
    
    for (int i = 0; i < n; ++i) {
        if (min_dist[i] == INT_MAX) ans_count ++;
        else                        max_ans = max(max_ans, min_dist[i]); 
    }
}