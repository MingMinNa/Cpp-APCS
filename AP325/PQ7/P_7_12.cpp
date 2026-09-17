#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d098

typedef long long LL;

struct Edge {
    int u, v, w;
};

int n, m;
LL ans = 0;
vector<Edge> edges;
vector<int> dsu;

void read_input();
void find_ans();
int dsu_root(int idx);
bool dsu_union(int idx_1, int idx_2);


int main()
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &n, &m);
    dsu.resize(n, -1);
    edges.resize(m);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", 
            &edges[i].u, 
            &edges[i].v, 
            &edges[i].w
        );
    }
}

void find_ans()
{
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    int cnt = 0;

    for (int i = 0; i < m && cnt < n - 1; ++i) {
        if (dsu_union(edges[i].u, edges[i].v)) {
            cnt ++;
            ans += edges[i].w;
        }
    }

    if (cnt < n - 1)
        ans = -1;
}

int dsu_root(int idx)
{
    if (dsu[idx] < 0) return idx;
    return dsu[idx] = dsu_root(dsu[idx]);
}

bool dsu_union(int idx_1, int idx_2)
{
    int root_1 = dsu_root(idx_1), root_2 = dsu_root(idx_2);
    int rank_1 = abs(dsu[root_1]), rank_2 = abs(dsu[root_2]);

    if (root_1 == root_2) return false;

    if (rank_1 > rank_2) {
        dsu[root_2] = root_1;
    }
    else if (rank_1 < rank_2) {
        dsu[root_1] = root_2;
    }
    else if (rank_1 == rank_2) {
        dsu[root_2] = root_1;
        dsu[root_1] --;
    }
    
    return true;
}