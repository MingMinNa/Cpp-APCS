#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c292 (3. 數字龍捲風)

const int dirs[4][2] = {
    { 0, -1},
    {-1,  0},
    { 0,  1}, 
    { 1,  0}
};

int N, dir;
vector<vector<int>> table;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{
    scanf("%d", &N);
    scanf("%d", &dir);
    table.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &table[i][j]);
        }
    }
}

void find_ans() 
{
    int pos_x = N / 2;
    int pos_y = N / 2;
    int dist = 1;
    
    for (int i = 0; i < N * N;) {
        for (int j = 0; j < 2 && i < N * N; ++j) {
            for (int k = 0; k < dist && i < N * N; ++k) {
                printf("%d", table[pos_y][pos_x]);
                pos_y += dirs[dir][0];
                pos_x += dirs[dir][1];
                ++i;
            }
            dir = (dir + 1) % 4;
        }
        dist ++;
    }
}