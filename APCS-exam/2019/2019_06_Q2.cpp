#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=e287 (2. 機器人的路徑)

typedef long long LL;

const int dirs[4][2] = {
    { -1,  0},
    {  1,  0},
    {  0, -1},
    {  0,  1}
};

int n, m, val = INT_MAX;
pair<int, int> pos = {1, 1};
vector<vector<int>> table;

void read_input();
LL find_ans();


int main() 
{
    read_input();
    printf("%lld", find_ans());
}

void read_input() 
{
    scanf("%d %d", &n, &m);
    table.resize(n + 2, vector<int>(m + 2, -1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            scanf("%d", &table[i][j]);

            if (table[i][j] < val) {
                val = table[i][j];
                pos = {i, j};
            }
        }
    }
}

LL find_ans() 
{
    LL ans = 0;
    pair<int, int> next_pos;

    while (true) {

        val = INT_MAX;
        ans += table[pos.first][pos.second];
        table[pos.first][pos.second] = -1;
        
        for (int i = 0; i < 4; ++i) {

            int next_y = pos.first  + dirs[i][1];
            int next_x = pos.second + dirs[i][0];

            if (table[next_y][next_x] > 0 && table[next_y][next_x] < val) {
                val = table[next_y][next_x];
                next_pos = {next_y, next_x};
            }
        }

        if (val == INT_MAX) break;
        pos = next_pos; 
    }
    
    return ans;
}