#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f313 (2. 人口遷移)

const int dirs[4][2] = {
    {  0, -1},
    {  0,  1},
    {  1,  0},
    { -1,  0}
};

int R, C, k, m, min_num = INT_MAX, max_num = INT_MIN;
vector<vector<int>> table;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
    printf("%d\n%d", min_num, max_num);
}

void read_input() 
{
    scanf("%d %d %d %d", &R, &C, &k, &m);
    table.resize(R + 2, vector<int>(C + 2, -1));

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            scanf("%d", &table[i][j]);
        }
    }
}

void find_ans() 
{
    for (int l = 0; l < m; ++l) {

        vector<vector<int>> temp(table);

        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {

                if (table[i][j] == -1) continue;

                for (int l = 0; l < 4; ++l) {

                    int next_y = i + dirs[l][0];
                    int next_x = j + dirs[l][1];

                    if (table[next_y][next_x] == -1) continue;

                    temp[i][j] -= table[i][j] / k;
                    temp[next_y][next_x] += table[i][j] / k;
                }
            }
        }

        table = move(temp);
    }

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {

            if (table[i][j] == -1) continue;
            
            min_num = min(min_num, table[i][j]);
            max_num = max(max_num, table[i][j]);
        }
    }
}