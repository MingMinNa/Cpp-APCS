#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=q839 (4. 分組遊戲)

struct Edge {
    int s, t, val;

    Edge(int s, int t, int val) : s(s), t(t), val(val) {}

    bool operator>(const Edge& other) const 
    {
        return val > other.val;
    }
};

int n, k, ans = INT_MAX;
vector<int> parent;
vector<vector<int>> table;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

void read_input();
void find_ans();
bool union_root(int a, int b);
int find_root(int a);


int main()
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d %d", &n, &k);

    table.resize(n, vector<int>(n));
    parent.resize(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &table[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pq.push(Edge(i, j, table[i][j]));
        }
    }
}

void find_ans()
{
    while (!pq.empty() && n > k) {

        Edge e = pq.top(); pq.pop();
        bool res = union_root(e.s, e.t);

        if (!res) continue;
        n --;
    }
    
    while (!pq.empty()) {
        
        Edge e = pq.top(); pq.pop();
        ans = e.val;

        if (find_root(e.s) != find_root(e.t)) break;
    }
}

bool union_root(int a, int b)
{
    int root_a = find_root(a), root_b = find_root(b);
    int rank_a = (-1) * parent[root_a], rank_b = (-1) * parent[root_b];

    if (root_a == root_b) return false;

    if (rank_a >= rank_b) {
        parent[root_a] -= rank_b;
        parent[root_b] = root_a;
    }
    else {
        parent[root_b] -= rank_a;
        parent[root_a] = root_b;
    }
    
    return true;
}

int find_root(int a)
{
    if (parent[a] < 0) return a;
    return parent[a] = find_root(parent[a]);
}