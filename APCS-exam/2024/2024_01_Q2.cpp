#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=m932 (2. 蜜蜂觀察)

int m, n, k;
vector<int> ops;
vector<vector<char>> grid;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{
    scanf("%d %d %d", &m, &n, &k);
    grid.resize(m + 2, vector<char>(n + 2));
    ops.resize(k);
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf(" %c", &grid[i][j]);
        }
    }

    for (int i = 0; i < k; ++i) {
        scanf("%d", &ops[i]);
    }
}

void find_ans() 
{
    set<char> char_set;
    pair<int, int> curr_pos = {m, 1};

    auto next = [&](int i) -> pair<int,int> {

        if      (i == 0) return {curr_pos.first - 1, curr_pos.second    };
        else if (i == 1) return {curr_pos.first    , curr_pos.second + 1};
        else if (i == 2) return {curr_pos.first + 1, curr_pos.second + 1};
        else if (i == 3) return {curr_pos.first + 1, curr_pos.second    };
        else if (i == 4) return {curr_pos.first    , curr_pos.second - 1};
        else if (i == 5) return {curr_pos.first - 1, curr_pos.second - 1};

        return curr_pos;
    };
    
    for (int i = 0; i < k; ++i) {

        pair<int, int> next_pos = next(ops[i]);
        auto [r, c] = next_pos;
        
        if (grid[r][c] == 0) {
            r = curr_pos.first;
            c = curr_pos.second;
            next_pos = curr_pos;
        }

        printf("%c", grid[r][c]);
        char_set.insert(grid[r][c]);
        curr_pos = next_pos;
    }
    
    printf("\n%d", char_set.size());
}