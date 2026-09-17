#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=m371 (2. 卡牌遊戲)

int n, m;
vector<vector<int>> table;

const int dirs[4][2] = {
    {  0, -1},
    {  0,  1},
    { -1,  0},
    {  1,  0},
};

void read_input();
int find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    cout << find_ans();
}

void read_input() 
{
    cin >> n >> m;
    table.resize(n + 2, vector<int>(m + 2, -1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> table[i][j];
        }
    }
}

int find_ans() 
{
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if ( 
                table[i][j] == table[i][j - 1] || 
                table[i][j] == table[i - 1][j]
            ) {
                q.push({i, j});
            }
        }
    }

    int ans = 0;

    while (!q.empty()) {

        auto [row, col] = q.front(); q.pop();

        if (table[row][col] < 0) continue;
        
        bool match = false;
        int match_r, match_c;

        for (int i = 0; i < 4; ++i) {
            
            match_r = row + dirs[i][0];
            match_c = col + dirs[i][1];

            while (table[match_r][match_c] == -2) {
                match_r += dirs[i][0];
                match_c += dirs[i][1];
            }

            if (table[match_r][match_c] == table[row][col]) {
                match = true;
                break;
            }
        }

        if (!match) continue;

        ans += table[row][col];
        table[row][col] = -2;
        table[match_r][match_c] = -2;

        int neighbor_r, neighbor_c;

        for (int i = 0; i < 4; ++i) {

            neighbor_r = row + dirs[i][0];
            neighbor_c = col + dirs[i][1];
            
            while (table[neighbor_r][neighbor_c] == -2) {
                neighbor_r += dirs[i][0];
                neighbor_c += dirs[i][1];
            }

            if (table[neighbor_r][neighbor_c] > 0) 
                q.push({neighbor_r, neighbor_c});
        }
        
        for (int i = 0; i < 4; ++i) {

            neighbor_r = match_r + dirs[i][0];
            neighbor_c = match_r + dirs[i][1];

            while (table[neighbor_r][neighbor_c] == -2) {
                neighbor_r += dirs[i][0];
                neighbor_c += dirs[i][1];
            }

            if (table[neighbor_r][neighbor_c] > 0) 
                q.push({neighbor_r, neighbor_c});
        }
    }
    
    return ans;
}