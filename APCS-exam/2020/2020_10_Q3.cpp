#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f314 (3. 勇者修煉)

int m, n, ans = INT_MIN;
vector<vector<int>> table, dp;

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
    cin >> m >> n;

    table.resize(m + 1, vector<int>(n));
    dp.resize(m + 1, vector<int>(n, INT_MIN));

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> table[i][j];
        }
    }
}

void find_ans() 
{
    for (int i = 0; i < n; ++i) {
        dp[0][i] = 0;
    }
    
    vector<int> left(n), right(n);

    for (int i = 1; i <= m; ++i) {

        left[0] = dp[i - 1][0] + table[i][0];

        for (int j = 1; j < n; ++j) {
            left[j] = max(left[j - 1], dp[i - 1][j]) + table[i][j];
        }

        right[n - 1] = dp[i - 1][n - 1] + table[i][n - 1];

        for (int j = n - 2; j >= 0; --j) {
            right[j] = max(right[j + 1], dp[i - 1][j]) + table[i][j];
        }

        for (int j = 0; j < n; ++j) {
            dp[i][j] = max(left[j], right[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[m][i]);
    }
}