#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=m372 (3. 搬家)

int n, m, ans = 0;
vector<vector<char>> table;
map<pair<int, int>, pair<int, int>> parent;

void read_input();
void find_ans();
void combine_top(int r, int c);
void combine_down(int r, int c);
void combine_left(int r, int c);
void combine_right(int r, int c);
bool is_same(pair<int, int> a, pair<int, int> b);
void union_root(pair<int, int> a, pair<int, int> b);
pair<int, int> find_root(pair<int, int> a);


int main() 
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d %d", &n, &m);
    table.resize(n + 2, vector<char>(m + 2));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            parent[{i, j}] = {-1, -1};
            scanf(" %c", &table[i][j]);
        }
    }
}

void find_ans()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            if (table[i][j] == '0') continue; 

            ans = max(ans, 1);
            
            combine_top(i, j);
            combine_down(i, j);
            combine_left(i, j);
            combine_right(i, j);
        }
    }
}

void combine_top(int r, int c)
{
    const static set<char> CURR_PIECE = {'X', 'I', 'L', 'J'};
    const static set<char> TOP_PIECE  = {'X', 'I', '7', 'F'};

    if (
        CURR_PIECE.count(table[r][c]) && 
        TOP_PIECE.count(table[r - 1][c])
    ) {
        union_root({r, c}, {r - 1, c});
    }
}

void combine_down(int r, int c)
{
    const static set<char> CURR_PIECE = {'X', 'I', '7', 'F'};
    const static set<char> DOWN_PIECE = {'X', 'I', 'L', 'J'};

    if (
        CURR_PIECE.count(table[r][c]) && 
        DOWN_PIECE.count(table[r + 1][c])
    ) {
        union_root({r, c}, {r + 1, c});
    }
}

void combine_left(int r, int c)
{
    const static set<char> CURR_PIECE = {'X', 'H', '7', 'J'};
    const static set<char> LEFT_PIECE = {'X', 'H', 'L', 'F'};

    if (
        CURR_PIECE.count(table[r][c]) && 
        LEFT_PIECE.count(table[r][c - 1])
    ) {
        union_root({r, c}, {r, c - 1});
    }
}

void combine_right(int r, int c)
{
    const static set<char> CURR_PIECE  = {'X', 'H', 'L', 'F'};
    const static set<char> RIGHT_PIECE = {'X', 'H', '7', 'J'};

    if (
        CURR_PIECE.count(table[r][c]) && 
        RIGHT_PIECE.count(table[r][c + 1])
    ) {
        union_root({r, c}, {r, c + 1});
    }
}

bool is_same(pair<int, int> a, pair<int, int> b)
{
    return find_root(a) == find_root(b);
}

void union_root(pair<int, int> a, pair<int, int> b)
{
    pair<int, int> root_a = find_root(a), root_b = find_root(b);

    if (root_a == root_b) return;

    int rank_a = parent[root_a].first;
    int rank_b = parent[root_b].first;

    if (rank_a < rank_b) {
        parent[root_a].first += rank_b;
        parent[root_b] = root_a;
        ans = max(ans, parent[root_a].first * (-1));
    }
    else {
        parent[root_b].first += rank_a;
        parent[root_a] = root_b;
        ans = max(ans, parent[root_b].first * (-1));
    }
}

pair<int, int> find_root(pair<int, int> a)
{
    if (parent[a].first < 0) return a;
    return parent[a] = find_root(parent[a]);
}