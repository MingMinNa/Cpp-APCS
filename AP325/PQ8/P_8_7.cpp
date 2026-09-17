#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d106

int n, ans = 0;
vector<int> color, counter;
vector<vector<int>> children;
map<int, int> color_id;

void read_input();
void dfs(int v);


int main()
{
    read_input();
    dfs(0);
    printf("%d\n", ans);
}

void read_input()
{
    scanf("%d", &n);

    color.resize(n);
    children.resize(n);
    counter.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &color[i]);
    }

    int p, v;

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &p, &v);
        children[p].push_back(v);
    }

    // discretization
    for (int i = 0; i < n; ++i) {
        color_id.insert({color[i], 0});
    }

    int cnt = 0;

    for (auto &v : color_id) {
        v.second = cnt;
        cnt ++;
    }
}

void dfs(int v)
{
    int cc = color_id[color[v]];
    
    counter[cc]++;
    ans = max(ans, counter[cc]);

    for (int &u : children[v]) {
        dfs(u);
    }

    counter[cc]--;
}