#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=g276 (2. 魔王迷宮)

struct Demon {
    int r, c, s, t;
    bool in_table;
};

int n, m, k, ans = 0;
vector<vector<char>> table;
vector<Demon> demons;

void read_input();
void find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << ans;
}

void read_input() 
{
    cin >> n >> m >> k;

    table.resize(n, vector<char>(m));
    demons.resize(k);

    for (int i = 0; i < k; ++i) {
        cin >> demons[i].r >> demons[i].c 
            >> demons[i].s >> demons[i].t;
        demons[i].in_table = true;
    }
}

void find_ans() 
{
    auto out_bound = [&](int i) {
        return \
            demons[i].r < 0  || 
            demons[i].r >= n || 
            demons[i].c < 0  || 
            demons[i].c >= m;
    };

    int remaining = k;

    while (remaining > 0) {

        for (int i = 0; i < k; ++i) {
            if (demons[i].in_table == false) continue;
            table[demons[i].r][demons[i].c] = true;
        }

        set<pair<int,int>> update;
        
        for (int i = 0; i < k; ++i) {

            if (demons[i].in_table == false) continue;

            demons[i].r += demons[i].s;
            demons[i].c += demons[i].t;

            if (out_bound(i)) {
                demons[i].in_table = false;
                remaining --;
            }
            else if (table[demons[i].r][demons[i].c] == true) {
                update.insert({demons[i].r, demons[i].c});
                demons[i].in_table = false;
                remaining --;
            }
        }

        for (auto &e: update) {
            table[e.first][e.second] = false;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += table[i][j];
        }
    }
}