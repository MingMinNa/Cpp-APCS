#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d091

int n, m, ans = 0;
vector<int> dsu; // disjoint set

void read_input();
void find_ans();
int dsu_root(int idx);
void dsu_union(int idx_1, int idx_2);


int main()
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d %d", &n, &m);
    dsu.resize(n + 1);

    int t, t2;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        dsu[i] = -t;
    }
    
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &t, &t2);
        dsu_union(t + 1, t2 + 1);
    }
}

void find_ans()
{
    for (int i = 1; i <= n; ++i) {
        if (dsu[i] < 0) ans = max(ans, abs(dsu[i]));
    }
}

int dsu_root(int idx)
{
    if (dsu[idx] <= 0) return idx;
    return dsu[idx] = dsu_root(dsu[idx]);
}

void dsu_union(int idx_1, int idx_2)
{
    int root_1 = dsu_root(idx_1), root_2 = dsu_root(idx_2);
    int rank_1 = abs(dsu[root_1]), rank_2 = abs(dsu[root_2]);

    if (root_1 == root_2) return;

    if (rank_1 >= rank_2) {
        dsu[root_1] += dsu[root_2];
        dsu[root_2] = root_1;
    }
    else {
        dsu[root_2] += dsu[root_1];
        dsu[root_1] = root_2;
    }
}