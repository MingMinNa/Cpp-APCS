#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=g596 (2. 動線安排)

const int dirs[4][2] = {
    {  0, -1},
    {  0,  1},
    {  1,  0},
    { -1,  0}
};

int n, m, h, ans_max_count = 0, ans_count = 0;
vector<vector<char>> table;

inline bool out_bound(int r, int c);
void read_input();
void put(int r, int c);
void remove(int r, int c);
void update_answer();


int main() 
{    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    read_input();
    cout << ans_max_count << endl << ans_count;
}

inline bool out_bound(int r, int c) 
{
    return r < 0 || r >= n || c < 0 || c >= m;
}

void read_input() 
{
    cin >> n >> m >> h;
    table.resize(n, vector<char>(m, 0));

    int r, c, op;

    for (int i = 0; i < h; ++i) {

        cin >> r >> c >> op;
        
        if (op == 0) put(r, c);
        else        remove(r, c);
        
        update_answer();
    }
}

void put(int r, int c) 
{
    remove(r, c);
    table[r][c] = -1;

    for (int d = 0; d < 4; ++d) {
        
        int x = r + dirs[d][0];
        int y = c + dirs[d][1];

        bool found = false;

        while (!out_bound(x, y)) {

            if (table[x][y] == -1) { found = true; break; }

            x += dirs[d][0];
            y += dirs[d][1];
        }

        if (found) {
            if (d < 2) for (int j = min(c, y) + 1; j < max(c, y); ++j) table[r][j] ++;
            else       for (int i = min(r, x) + 1; i < max(r, x); ++i) table[i][c] ++;
        }
    }
}

void remove(int r, int c) 
{
    for (int d = 0; d < 4; ++d) {
        
        int x = r + dirs[d][0];
        int y = c + dirs[d][1];

        bool found = false;

        while (!out_bound(x, y)) {

            if (table[x][y] ==  0) break;
            if (table[x][y] == -1) { found = true; break; }

            x += dirs[d][0];
            y += dirs[d][1];
        }

        if (found) {
            if (d < 2) for (int j = min(c, y) + 1; j < max(c, y); ++j) table[r][j] --;
            else       for (int i = min(r, x) + 1; i < max(r, x); ++i) table[i][c] --;
        }
    }

    table[r][c] = 0;
}

void update_answer() 
{
    int cnt = 0;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (table[i][j] != 0)
                cnt ++;

    ans_count = cnt;
    ans_max_count = max(ans_max_count, cnt);
}