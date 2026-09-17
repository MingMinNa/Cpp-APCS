#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d103

int n, longest = 0, max_step = 0;
vector<int> leng, d, step;
vector<vector<int>> child; 

void read_input();
void find_ans();
void dfs(int v);
 

int main() 
{ 
    read_input();
    find_ans();
    printf("%d\n%d\n", longest, max_step);
}

void read_input()
{
    scanf("%d", &n); 

    d.resize(n);
    leng.resize(n);
    step.resize(n);
    child.resize(n);

    int v, w; 

    for (int i = 1; i < n; ++i) { 
        
        scanf("%d %d", &v, &w); 
        
        leng[i] = w; // length of edge (i, parent[i]) 
        child[v].push_back(i); 
    } 
}

void find_ans()
{
    d[0] = 0;
    step[0] = 0; 
    dfs(0); // DFS from root 0 
}

void dfs(int v) 
{ 
    for (int &ch : child[v]) { 
        d[ch] = d[v] + leng[ch]; 
        step[ch] = step[v] +1; 
        longest = max(longest, d[ch]); 
        max_step = max(max_step, step[ch]); 
        dfs(ch); 
    } 
} 