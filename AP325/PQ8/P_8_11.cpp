#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d109

int n;
vector<int> f0, f1, w;
vector<vector<int>> children;

void read_input();
void dfs(int r);


int main()
{
    read_input();
    dfs(1);
    printf("%d\n", max(f0[1], f1[1]));
}

void read_input()
{
    w.resize(2);
    scanf("%d %d", &n, &w[1]);

    w.resize(n + 1);
    f0.resize(n + 1, 0);
    f1.resize(n + 1, 0);
    children.resize(n + 1);

    int p;
    
    for (int i = 2; i <= n; ++i) {
        scanf("%d %d", &p, &w[i]);
        children[p].push_back(i);
    }
}

void dfs(int r)
{
    f0[r] = 0;
    f1[r] = w[r];

    for (int &c : children[r]) {
        dfs(c);
        f0[r] += max(f0[c], f1[c]);
        f1[r] += f0[c];
    }
}