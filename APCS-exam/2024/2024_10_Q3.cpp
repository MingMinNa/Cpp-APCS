#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=o713 (3. 連鎖反應)

int m, n, q, start_r, start_c;
vector<vector<int>> grid;

void read_input();
void find_ans();
int simulate(int t);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
}

void read_input()
{
    cin >> m >> n >> q;
    grid.resize(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            cin >> grid[i][j];

            if (grid[i][j] == -2) {

                start_r = i;
                start_c = j;
                grid[i][j] = 0;
            }
        }
    }
}

void find_ans()
{
    int rad = 0;

    for (int jump = (m * n) / 2; jump >= 1; jump >>= 1) {
        while (rad + jump <= m * n && simulate(rad + jump) < q) {
            rad += jump;
        }
    }

    cout << rad + 1;
}

int simulate(int t) 
{
    int covered = 0;

    vector<vector<int>> dist_grid = grid;
    vector<vector<char>> visited(m, vector<char>(n, 0));
    queue<pair<int,int>> que;

    dist_grid[start_r][start_c] = t;
    visited[start_r][start_c] = 1;

    que.push({start_r, start_c});
    covered++;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!que.empty()) {

        auto [r, c] = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {

            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (grid[nr][nc] == -1)                     continue; 

            if (dist_grid[r][c] >= 1) {
                if (!visited[nr][nc]) {

                    covered ++;
                    visited[nr][nc] = 1;

                    dist_grid[nr][nc] = max(dist_grid[nr][nc], dist_grid[r][c] - 1);
                    que.push({nr, nc});
                } 
                else if (dist_grid[nr][nc] < dist_grid[r][c] - 1) {
                    dist_grid[nr][nc] = dist_grid[r][c] - 1;
                    que.push({nr, nc});
                }
            }
        }
    }
    
    return covered;
}