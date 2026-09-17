#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=m373 (4. 投資遊戲)

int n, k, ans = INT_MIN;
vector<int> vec;
vector<vector<int>> dp;

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
    cin >> n >> k;
    vec.resize(n + 1);
    dp.resize(k + 2, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
}

void find_ans()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k + 1; ++j) {
            dp[j][i] = max(
                dp[j - 1][i - 1],
                dp[j][i - 1] + vec[i]
            );
        }
    }

    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[k + 1][i]);
    }
}