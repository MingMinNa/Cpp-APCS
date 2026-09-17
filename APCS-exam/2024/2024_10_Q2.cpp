#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=o712 (2. 蒐集寶石)

int M, N, k, r, c, ans = 0;
vector<vector<int>> table;

const int dirs[4][2] = {
    {  0,  1},
    {  1,  0},
    {  0, -1},
    { -1,  0},
};

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
    cout << ans;
}

void read_input() 
{
    cin >> M >> N >> k >> r >> c;
    table.resize(M + 2, vector<int>(N + 2, -1));

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> table[i][j];
        }
    }
}

void find_ans() 
{
    int score = 0, dir = 0;
    r ++, c ++;

    while (table[r][c] > 0) {

        score += table[r][c];
        ans ++;
        table[r][c] --;

        if (score % k == 0) {
            dir = (dir + 1) % 4;
        }

        int next_r = r + dirs[dir][0];
        int next_c = c + dirs[dir][1];

        while (table[next_r][next_c] == -1) {
            
            dir = (dir + 1) % 4;
            next_r = r + dirs[dir][0];
            next_c = c + dirs[dir][1];
        }

        r = next_r;
        c = next_c;
    }
}