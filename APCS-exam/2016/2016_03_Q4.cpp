#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=b967 (4. 血緣關係)

int n, root, ans = 0;
vector<vector<int>> children;

void read_input();
int dfs(int u);


int main() 
{
    read_input();
    dfs(root);
    printf("%d", ans);
}

void read_input() 
{    
    scanf("%d", &n);
    children.resize(n);
    root = (n - 1) * n / 2;

    int p, c;

    for (int i = 0; i < n - 1; ++i) {

        scanf("%d %d", &p, &c);
        
        children[p].push_back(c);
        root -= c;
    }
}

int dfs(int u) 
{
    int max_dist[2] = {0, 0};

    for (const auto &c : children[u]) {
        
        int dist = dfs(c) + 1;

        if (dist >= max_dist[0]) {
            max_dist[1] = max_dist[0];
            max_dist[0] = dist;
        }
        else if (dist > max_dist[1]) {
            max_dist[1] = dist;
        }
    }

    ans = max(ans, max_dist[0] + max_dist[1]);
    return max_dist[0];
}