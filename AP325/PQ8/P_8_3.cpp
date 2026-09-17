#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d104

typedef long long LL;

int n;
LL median = -1, total = 0; 
vector<int> num;
vector<vector<pair<int,int>>> child; 

void read_input();
void dfs(int v);
 

int main() 
{ 
    read_input();
    dfs(0); 
    printf("%lld\n%lld", median, total); 
} 
 
void read_input()
{
    scanf("%d", &n); 
    num.resize(n);
    child.resize(n);
 
    int v, w; 

    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &v, &w); 
        child[v].push_back({i, w}); 
    }
}

void dfs(int v) 
{ 
    int u, w;
    
    for (auto &e: child[v]) { 

        u = e.first;
        w = e.second; 
        
        dfs(u); 
        total += min(num[u], n - num[u]) * w; 
        num[v] += num[u]; 
    } 

    num[v] ++; // add itself 
    
    if (median < 0 && num[v] >= (n + 1) / 2) {
        median = v; 
    }
} 