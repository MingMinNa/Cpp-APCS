#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=j125 (4. 蓋步道)

int n, min_height = 0, len = 0;
vector<vector<int>> table;

int dirs[][2] = {
    { -1,  0},
    {  1,  0},
    {  0, -1},
    {  0,  1},
};

void read_input();
void find_ans();
pair<bool,int> bfs(int h);


int main()
{
    read_input();
    find_ans();
    printf("%d\n%d", min_height, len);
}

void read_input()
{
    scanf("%d", &n);
    table.resize(n + 2, vector<int>(n + 2, -1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &table[i][j]);
        }
    }
}

void find_ans()
{
    int left = 0, right = 1000000;

    for (int jump = (right - left) >> 1; jump >= 1; jump >>= 1) {
        while (right - jump > left && bfs(right - jump).first) {
            right -= jump;
        }
    }

    min_height = right;
    len = bfs(min_height).second;
}

pair<bool,int> bfs(int h)
{
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n + 2, vector<int>(n + 2, -1));

    q.push({1,1});
    dist[1][1] = 0;

    while (!q.empty()) {

        auto [r, c] = q.front(); q.pop();

        if (r == n && c == n) {
            return {true, dist[r][c]};
        }

        for (int i = 0; i < 4; ++i) {
            
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            if (table[nr][nc] == -1) continue;
            if (dist[nr][nc]  != -1) continue;

            if (abs(table[r][c] - table[nr][nc]) <= h) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return {false, -1};
}