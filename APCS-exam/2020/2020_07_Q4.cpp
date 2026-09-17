#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f582 (4. 病毒演化)

typedef long long LL;

int n, m;
int root_node = -1;
vector<string> RNA;
vector<vector<int>> children;
vector<vector<LL>> dp;

map<char, int> mapping_table = {
    {'A', 0}, 
    {'U', 1}, 
    {'C', 2}, 
    {'G', 3}, 
    {'@', 4}
};

void read_input();
LL find_ans();
LL solve_dp(int node, int pos, int k);


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
    RNA.resize(n + 1);
    children.resize(n + 1);

    int s, t;

    for (int i = 0; i < n; ++i) {

        cin >> s >> t >> RNA[s];
        
        if (s == t) root_node = s;
        else        children[t].push_back(s);
    }

    dp.assign(n + 1, vector<LL>(4, -1));
}

LL find_ans()
{
    LL total = 0;

    for (int pos = 0; pos < m; ++pos) {
        for (auto &row : dp) {
            fill(row.begin(), row.end(), -1ll);
        }

        LL best = INT_MAX;

        for (int k = 0; k < 4; ++k) {
            best = min(best, solve_dp(root_node, pos, k));
        }

        total += best;
    }

    return total;
}

LL solve_dp(int node, int pos, int k)
{
    LL &res = dp[node][k];
    if (res != -1) return res;

    char ch = RNA[node][pos];
    int fixed = mapping_table[ch];

    // if the character is fixed, then other characters at this position are impossible (invalid state).
    if (fixed != 4 && fixed != k) return res = INT_MAX;
    if (children[node].empty())   return res = 0;

    LL sum = 0, best_child, val;

    for (int child : children[node]) {

        best_child = INT_MAX;

        for (int q = 0; q < 4; ++q) {
            val = solve_dp(child, pos, q);
            best_child = min(best_child, val + (q != k));
        }

        sum += best_child;
    }
    
    return res = sum;
}