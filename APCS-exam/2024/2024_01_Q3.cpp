#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=m933 (3. 邏輯電路)


int p, q, r, m;
vector<int> element;
vector<char> visited;
vector<vector<int>> table;
vector<pair<int, int>> dp;

void read_input();
void find_ans();
pair<int, int> dfs(int idx);


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 

    read_input();
    find_ans();
}

void read_input()
{
    cin >> p >> q >> r >> m;

    dp.resize(p + q + r + 1);
    element.resize(p + q + 1);
    table.resize(p + q + r + 1);
    visited.resize(p + q + r + 1);

    for (int i = 1; i <= p + q; i++) {
        cin >> element[i];
    }

    int a, b;

    while (m > 0) {
        
        cin >> a >> b;

        table[b].push_back(a);
        m --;
    }
}

void find_ans()
{
    int delay = INT_MIN;
    vector<int> ans;

    for (int i = p + q + 1; i <= p + q + r; ++i) {
        auto d = dfs(i);
        ans.push_back(d.first);
        delay = max(delay, d.second);
    }

    cout << delay << "\n";
    for (auto i: ans) {
        cout << i << " ";
    }
}

pair<int, int> dfs(int idx)
{
    if (idx <= p) {
        visited[idx] = 1;
        return dp[idx] = {element[idx], 0};
    }
        
    if (idx > p + q && idx <= p + q + r) return dfs(table[idx][0]);
    if (visited[idx])                    return dp[idx];

    visited[idx] = 1;
    auto x = dfs(table[idx][0]);

    if (element[idx] == 4) return dp[idx] = {!x.first, x.second+1};

    auto y = dfs(table[idx][1]);

    if (element[idx] == 1) return dp[idx] = {(x.first && y.first), max(x.second, y.second) + 1};
    if (element[idx] == 2) return dp[idx] = {(x.first || y.first), max(x.second, y.second) + 1};

    return dp[idx] = {(x.first ^ y.first) , max(x.second, y.second) + 1};
}