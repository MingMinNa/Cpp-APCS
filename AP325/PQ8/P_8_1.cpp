#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d102

int n, total = 0;
vector<int> tour; 
vector<vector<int>> adj; 

void read_input();
void find_ans();
void dfs(int p, int v);


int main() 
{ 
    read_input();
    find_ans();

    printf("%d\n%d", total * 2, tour[0]); 
    for (size_t i = 1; i < tour.size(); ++i) {
        printf(" %d", tour[i]); 
    }
} 

void read_input()
{
    scanf("%d", &n);
    adj.resize(n);

    int u, v, w; 

    for (int i = 0;i < n - 1; ++i) { 

        scanf("%d %d %d", &u, &v, &w); 
        
        adj[u].push_back(v); 
        adj[v].push_back(u); 
        total += w; // total edge weight 
    } 
}

void find_ans()
{
    for (int i = 0; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end()); 
    }

    dfs(-1, 0);
}

void dfs(int p, int v) 
{ 
    tour.push_back(v); 

    for (int &u: adj[v]) { 

        if (u == p) continue; 
        
        dfs(v, u); 
        tour.push_back(v); 
    } 
} 