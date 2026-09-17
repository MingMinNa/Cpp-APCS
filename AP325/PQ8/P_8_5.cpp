#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d105

typedef long long LL;

int n, m;
vector<int> lc, rc;
vector<LL> w, goods_weight;

void read_input();
void find_ans();
LL dfs_update(int v);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
}

void read_input()
{
    cin >> n >> m;

    w.resize(2 * n + 1, 0);
    lc.resize(2 * n + 1, 0);
    rc.resize(2 * n + 1, 0);
    goods_weight.resize(m);

    for (int i = n; i < n * 2; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> goods_weight[i];
    }

    int v;
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> v;
        cin >> lc[v] >> rc[v];
    }

    w[1] = dfs_update(1);
}

void find_ans()
{
    int v = 1;

    for (int i = 0; i < m; ++i, v = 1) {

        while (v < n) {
            
            if  (w[lc[v]] <= w[rc[v]]) v = lc[v];
            else                       v = rc[v];

            w[v] += goods_weight[i];
        }

        if (i > 0) cout << " ";
        cout << v;
    }

    cout << "\n";
}

LL dfs_update(int v)
{
    if (v >= n) return w[v]; 
    
    w[v] = dfs_update(lc[v]) + dfs_update(rc[v]);
    return w[v];
}