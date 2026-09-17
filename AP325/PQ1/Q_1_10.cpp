#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d008

int n, best = 0;
vector<int> position;
vector<vector<int>> board;

void read_input();
void put_queen(int index, int sum);


int main() 
{
    read_input();
    put_queen(0, 0);
    printf("%d", best);
}

void read_input()
{
    scanf("%d", &n);
    position.resize(n, -1);
    board.resize(n, vector<int>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &board[i][j]);
        }
    }
}

void put_queen(int index, int sum) 
{
    best = max(best, sum);
    
    if (index >= n) return;

    vector<char> valid_pos(n, 1);

    for (int i = 0; i < index; ++i) {

        if (position[i] == -1) continue;
        
        valid_pos[position[i]] = 0;

        int diag_1 = position[i] - (index - i), 
            diag_2 = position[i] + (index - i);

        if (diag_1 >= 0) valid_pos[diag_1] = 0;
        if (diag_2 <  n) valid_pos[diag_2] = 0;
    }

    for (int i = 0; i < n; ++i) {

        if (valid_pos[i] == 0) continue;

        position[index] = i;
        put_queen(index + 1, board[i][index] + sum);
    }

    position[index] = -1;
    put_queen(index + 1, sum);
}