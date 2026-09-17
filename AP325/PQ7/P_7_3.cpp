#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d092

typedef long long LL;

int m, n;
LL ans = 0;
pair<int, int> start_pos;
vector<vector<int>> table;

auto table_at = [](pair<int, int> pos) {
    return table[pos.first][pos.second];
};

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &m, &n);
    table.resize(m + 2, vector<int>(n + 2, INT_MAX));
    start_pos = {0, 0};

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {

            scanf("%d", &table[i][j]);
            
            if (table[i][j] < table_at(start_pos)) {
                start_pos = {i, j};
            }
        }
    }
}

void find_ans()
{
    pair<int, int> curr_pos = start_pos, next_pos;

    int dirs[4][2] = {
        {-1,  0}, 
        { 1,  0},
        { 0, -1},
        { 0,  1}
    };

    auto table_nearby = [&](pair<int, int> pos, int idx) {
        return table[pos.first + dirs[idx][0]][pos.second + dirs[idx][1]];
    };

    while (table_at(curr_pos) < INT_MAX) {
        
        ans += table_at(curr_pos);
        table[curr_pos.first][curr_pos.second] = INT_MAX;

        int idx = 0;
        
        for (int i = 0; i < 4; ++i) {
            if (table_nearby(curr_pos, i) < table_nearby(curr_pos, idx)) {
                idx = i;
            }
        }

        curr_pos = {
            curr_pos.first + dirs[idx][0],
            curr_pos.second + dirs[idx][1]
        };
    }
}