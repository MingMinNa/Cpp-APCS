#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d112
/* Minimum dominating set */

typedef long long LL;

struct State {
    LL state[3];
    // [0]: In dominating set
    // [1]: Out of dominating set, but child(children) in the set
    // [2]: Out of dominating set, but parent in the set
};

int n;
vector<vector<int>> adj_lst;
vector<State> dp;
vector<char> visited;

void read_input();
void dfs(int u);


int main() 
{
    read_input();
    dfs(1);
    printf("%lld\n", min(dp[1].state[0], dp[1].state[1]));
}

void read_input() 
{
    scanf("%d", &n);

    dp.resize(n + 1);
    adj_lst.resize(n + 1);
    visited.resize(n + 1);

    int u, v;

    for (int i = 0; i < n - 1; ++i) {

        scanf("%d %d", &u, &v);

        adj_lst[u].push_back(v);
        adj_lst[v].push_back(u);
    }
}

void dfs(int u) 
{
    visited[u] = 1;
    dp[u].state[0] = 1;
    dp[u].state[1] = 0;
    dp[u].state[2] = 0;  

    bool has_child_in_set = false;
    LL increase = INT_MAX;         // For state[1]
    LL sum01 = 0;                  // For state[1]

    for (int e : adj_lst[u]) {

        if (visited[e]) continue;
        dfs(e);

        // --- state[0] ---
        dp[u].state[0] += min({
            dp[e].state[0],
            dp[e].state[1],
            dp[e].state[2]
        });

        // --- state[1] ---
        if (dp[e].state[0] <= dp[e].state[1]) {
            sum01 += dp[e].state[0];
            has_child_in_set = true;
        } 
        else {
            sum01 += dp[e].state[1];
            increase = min(increase, dp[e].state[0] - dp[e].state[1]);
        }

        // --- state[2] ---
        if (dp[e].state[1] == INT_MAX) {
            dp[u].state[2] = INT_MAX;
        }
        else if (dp[u].state[2] < INT_MAX) {
            dp[u].state[2] += dp[e].state[1];
        }
    }

    // handle state[1]
    if (increase == INT_MAX && !has_child_in_set) {
        dp[u].state[1] = INT_MAX;
    } 
    else {
        dp[u].state[1] = sum01;
        
        if (!has_child_in_set) {
            dp[u].state[1] += increase;
        }
    }
}