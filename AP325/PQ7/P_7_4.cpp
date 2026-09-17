#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d093

int m, n, ans = -1;
vector<vector<char>> table;
vector<vector<int>> min_turn;

void read_input();
void bfs();


int main()
{
    read_input();
    bfs();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d %d", &m, &n);
    table.resize(m + 2, vector<char>(n + 2, '1'));
    min_turn.resize(m + 2, vector<int>(n + 2, -1));
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf(" %c", &table[i][j]);
        }
    }
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    min_turn[1][1] = 0;

    int dirs[4][2] = {
        {-1,  0}, 
        { 1,  0},
        { 0, -1},
        { 0,  1}
    };

    while (!q.empty() && min_turn[m][n] < 0) {

        auto pos = q.front(); q.pop();
        int r = pos.first, c = pos.second;

        for (int i = 0; i < 4; ++i) {

            int next_r = r + dirs[i][0], next_c = c + dirs[i][1];
            
            while (table[next_r][next_c] == '0') {

                if (min_turn[next_r][next_c] == -1) {
                    min_turn[next_r][next_c] = min_turn[r][c] + 1;
                    q.push({next_r, next_c});
                }

                next_r += dirs[i][0];
                next_c += dirs[i][1];
            }
        }
    }

    // the destination is reachable.
    if (min_turn[m][n] > 0) ans = min_turn[m][n] - 1;

    // the table is 1 x 1 (the starting point is the destination)
    else if (min_turn[m][n] == 0) ans = min_turn[m][n];

    // the destination is unreachable.
    else ans = -1;
}