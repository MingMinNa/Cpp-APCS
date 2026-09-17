#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d097

typedef long long LL;

int m, n, k;
LL total_max = 0, total_n = 0;
vector<int> dsu; 
vector<vector<char>> table;
vector<pair<int, int>> dig;

int dirs[4][2] = {
    {-1,  0},
    { 1,  0},
    { 0, -1},
    { 0,  1}
};

void read_input();
void find_ans();
int dfs(int v, int root);
inline int idx(int r, int c);
void dsu_union(int u, int v, int &max_count, int &n_area);
int dsu_root(int u);


int main()
{
    read_input();
    find_ans();
    printf("%lld\n%lld", total_max, total_n);
}

void read_input()
{
    scanf("%d %d %d", &m, &n, &k);

    table.resize(m + 2, vector<char>(n + 2, '0'));
    dsu.resize((m + 2) * (n + 2), -1);
    dig.resize(k);

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf(" %c", &table[i][j]);
        }
    }

    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &dig[i].first, &dig[i].second);
    }
}

void find_ans()
{
    int max_area = 0, n_area = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {

            int v = idx(i, j);
            
            if (table[i][j] == '1' && dsu[v] == -1) {

                int size = dfs(v, v);
                
                dsu[v] = -size;
                n_area ++;
                max_area = max(max_area, size);
            }
        }
    }
    
    total_max += max_area;
    total_n   += n_area;

    for (int i = 0; i < k; ++i) {

        int r = dig[i].first, c = dig[i].second;
        int v = idx(r, c);

        if (table[r][c] == '1') { 
            total_max += max_area;
            total_n   += n_area;
            continue;
        }

        table[r][c] = '1';
        dsu[v] = -1; 
        n_area ++;
        max_area = max(max_area, 1);

        int cur_max = 1;

        for (int d = 0; d < 4; ++d) {
            
            int next_r = r + dirs[d][0];
            int next_c = c + dirs[d][1];

            if (table[next_r][next_c] == '0') continue;
            dsu_union(v, idx(next_r, next_c), cur_max, n_area);
        }

        max_area = max(max_area, cur_max);

        total_max += max_area;
        total_n   += n_area;
    }
}

int dfs(int v, int root)
{
    dsu[v] = root;
    int cnt = 1;

    for (int i = 0; i < 4; ++i) {

        int dr = dirs[i][0], dc = dirs[i][1];
        int r = v / (n + 2) + dr;
        int c = v % (n + 2) + dc;
        int u = idx(r, c);
        
        if (table[r][c] == '1' && dsu[u] == -1)
            cnt += dfs(u, root);
    }

    return cnt;
}

inline int idx(int r, int c) 
{ 
    return r * (n + 2) + c; 
}

int dsu_root(int u)
{
    if (dsu[u] < 0) return u;
    return dsu[u] = dsu_root(dsu[u]);
}

void dsu_union(int u, int v, int &max_count, int &n_area)
{
    int r1 = dsu_root(u), r2 = dsu_root(v);
    int rank_1 = -dsu[r1], rank_2 = -dsu[r2];

    if (r1 == r2) return;

    max_count = max(max_count, rank_1 + rank_2);
    n_area --;

    if (rank_1 > rank_2) {
        dsu[r1] += dsu[r2];
        dsu[r2] = r1;
    } 
    else {
        dsu[r2] += dsu[r1];
        dsu[r1] = r2;
    }
}