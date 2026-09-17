#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=j123 (2. 運貨站)

int R, C, n;
vector<pair<char, int>> vec;
vector<vector<int>> grid;

void read_input();
void find_ans();
bool place_A(int dist);
bool place_B(int dist);
bool place_C(int dist);
bool place_D(int dist);
bool place_E(int dist);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
}

void read_input() 
{
    cin >> R >> C >> n;
    vec.resize(n);
    grid.resize(R, vector<int>(C));

    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first >> vec[i].second;
    }
}

void find_ans() 
{
    bool res = false;
    int dump = 0, space = 0;
    
    for (int i = 0; i < n; ++i) {

        res = false;

        if (vec[i].first == 'A') res = place_A(vec[i].second);
        if (vec[i].first == 'B') res = place_B(vec[i].second);
        if (vec[i].first == 'C') res = place_C(vec[i].second);
        if (vec[i].first == 'D') res = place_D(vec[i].second);
        if (vec[i].first == 'E') res = place_E(vec[i].second);

        dump += (!res);
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            space += (grid[i][j] == 0);
        }
    }

    printf("%d %d", space, dump);
}

bool place_A(int dist) 
{
    int row;
    auto check = [&](int r) {
        return \
            !grid[dist][r]     && 
            !grid[dist + 1][r] && 
            !grid[dist + 2][r] && 
            !grid[dist + 3][r];
    };

    for (row = C - 1; row >= 0; --row) {
        if (!check(row)) break;
    }

    if (row == C - 1) return false;
    
    for (int i = 0; i < 4; ++i) {
        grid[dist + i][row + 1] = 1;
    }
    
    return true;
}

bool place_B(int dist) 
{
    int row;
    auto check = [&](int r) {
        return \ 
            !grid[dist][r]     && 
            !grid[dist][r + 1] && 
            !grid[dist][r + 2];
    };

    for (row = C - 3; row >= 0; --row) {
        if (!check(row)) break;
    }
    
    if (row == C - 3) return false;
    
    for (int i = 0; i < 3; ++i) {
        grid[dist][row + 1 + i] = 1;
    }

    return true;
}

bool place_C(int dist) 
{
    int row;
    auto check = [&](int r) {
        return \
            !grid[dist][r]     && 
            !grid[dist + 1][r] && 
            !grid[dist][r + 1] && 
            !grid[dist + 1][r + 1];
    };

    for (row = C - 2; row >= 0; --row) {
        if (!check(row)) break;
    }
    
    if (row == C - 2) return false;
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            grid[dist + i][row + 1 + j] = 1;
        }
    }

    return true;
}

bool place_D(int dist) 
{
    int row;
    auto check = [&](int r) {
        return \ 
            !grid[dist][r + 2]     && 
            !grid[dist + 1][r]     && 
            !grid[dist + 1][r + 1] && 
            !grid[dist + 1][r + 2];
    };

    for (row = C - 3; row >= 0; --row) {
        if (!check(row)) break;
    }
    
    if (row == C - 3) return false;
    
    grid[dist][row + 3] = 1;
    grid[dist + 1][row + 1] = 1;
    grid[dist + 1][row + 2] = 1;
    grid[dist + 1][row + 3] = 1;

    return true;
}

bool place_E(int dist) 
{
    int row;
    auto check = [&](int r) {
        return \
            !grid[dist][r + 1]     && 
            !grid[dist + 1][r]     && 
            !grid[dist + 1][r + 1] && 
            !grid[dist + 2][r]     && 
            !grid[dist + 2][r + 1];
    };

    for (row = C - 2; row >= 0; --row) {
        if (!check(row)) break;
    }
    
    if (row == C - 2) return false;
    
    grid[dist][row + 2] = 1;
    grid[dist + 1][row + 1] = 1;
    grid[dist + 1][row + 2] = 1;
    grid[dist + 2][row + 1] = 1;
    grid[dist + 2][row + 2] = 1;
    
    return true;
}