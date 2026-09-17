#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=k732 (2. 特殊位置)

int n, m;
vector<vector<int>> table;
set<pair<int,int>> position;

void read_input();
void find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
}

void read_input() 
{
    cin >> n >> m;
    table.resize(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> table[i][j];
        }
    }
}

void find_ans() 
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            int total = 0, x = table[i][j];
            int h_start = max(i - x, 0); 
            int h_end = min(i + x, n - 1);

            for (int h = h_start; h <= h_end; ++h) {

                int k_start = max(j - (x - abs(i - h)), 0); 
                int k_end = min(j + (x - abs(i - h)), m - 1);
                
                for (int k = k_start; k <= k_end; ++k) {
                    total += table[h][k];
                }
            }

            if (total % 10 == x) {
                position.insert({i, j});
            }
        }
    }

    cout << position.size() << endl;
    for (auto &p : position) {
        cout << p.first << " " << p.second << endl;
    }
}