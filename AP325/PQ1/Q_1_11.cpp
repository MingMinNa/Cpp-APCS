#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d009

int m, n;
vector<vector<int>> table;

void read_input();
int delete_border(int left, int right, int top, int bottom);


int main()
{
    read_input();
    printf("%d", delete_border(0, n - 1, 0, m - 1));
}

void read_input()
{
    scanf("%d %d", &m, &n);
    table.resize(m, vector<int>(n));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &table[i][j]);
        }
    }
}

int delete_border(int left, int right, int top, int bottom) 
{
    if (left >= right || top >= bottom) return 0;

    int left_1 = 0, right_1  = 0;
    int top_1  = 0, bottom_1 = 0;

    // left and right
    for (int i = top; i <= bottom; ++i) {
        if (table[i][left]  == 1) left_1 ++;
        if (table[i][right] == 1) right_1 ++;
    }

    // top and bottom
    for (int i = left; i <= right; ++i) {
        if (table[top][i]    == 1) top_1 ++;
        if (table[bottom][i] == 1) bottom_1 ++;
    }

    int best = INT_MAX;
    best = min(best, delete_border(left + 1, right, top, bottom) + min(left_1, bottom - top + 1 - left_1));
    best = min(best, delete_border(left, right - 1, top, bottom) + min(right_1, bottom - top + 1 - right_1));
    best = min(best, delete_border(left, right, top + 1, bottom) + min(top_1, right - left + 1 - top_1));
    best = min(best, delete_border(left, right, top, bottom - 1) + min(bottom_1, right - left + 1 - bottom_1));

    return best;
}