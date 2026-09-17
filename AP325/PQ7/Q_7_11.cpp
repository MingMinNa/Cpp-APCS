#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d101

typedef long long LL;

struct DSU {

    vector<int> parent;

    void reset(int n) 
    {
        parent.resize(n, -1);
    }

    void unite(int a, int b, set<pair<int, int>> &min_set) 
    {
        if (is_same(a, b)) return;

        int root_a = find_root(a);
        int root_b = find_root(b);

        int rank_a = abs(parent[root_a]);
        int rank_b = abs(parent[root_b]);

        min_set.erase({rank_a, root_a});
        min_set.erase({rank_b, root_b});

        if (rank_a >= rank_b) {
            parent[root_a] = (rank_a + rank_b) * (-1);
            parent[root_b] = root_a;
            min_set.insert({rank_a + rank_b, root_a});
        }
        else {
            parent[root_a] = root_b;
            parent[root_b] = (rank_a + rank_b) * (-1);
            min_set.insert({rank_a + rank_b, root_b});
        }
    }

    int find_root(int a) 
    {
        if (parent[a] < 0) return a;
        return parent[a] = find_root(parent[a]);
    }
    
    bool is_same(int a, int b) 
    {
        return find_root(a) == find_root(b);
    }
};

int n, k;
LL min_sum, max_sum;
DSU dsu;
vector<int> grid;
vector<int> paint;
set<pair<int,int>> min_set;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();

    printf("%lld\n", max_sum);
    printf("%lld\n", min_sum);
}

void read_input() 
{
    scanf("%d %d", &n, &k);

    dsu.reset(n);
    grid.resize(n);
    paint.resize(k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &grid[i]);

        if (i > 0 && grid[i] == 1 && grid[i - 1] == 1) {
            dsu.unite(i - 1, i, min_set);
        }
        else if (grid[i] == 1) {
            min_set.insert({1, i});
        }
    }

    for (int i = 0; i < k; ++i) {
        scanf("%d", &paint[i]);
    }
}

void find_ans() 
{
    max_sum = min_set.rbegin()->first; 
    min_sum = min_set.begin()->first;

    for (int i = 0; i < k; ++i) {

        int idx = paint[i] - 1;

        if (grid[idx] == 1) {
            max_sum += min_set.rbegin()->first;
            min_sum += min_set.begin()->first;
            continue;
        }

        grid[idx] = 1;
        min_set.insert({1, idx});

        if (idx >= 1 && grid[idx - 1] == 1) {
            dsu.unite(idx - 1, idx, min_set);
        }
        
        if (idx < n - 1 && grid[idx + 1] == 1) {
            dsu.unite(idx, idx + 1, min_set);
        }

        max_sum += min_set.rbegin()->first;
        min_sum += min_set.begin()->first;
    }
}