#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=i402 (4. 內積)

typedef long long LL;

int n, m, ans = INT_MIN;
vector<int> A, B;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
    printf("%d\n", ans);
}

void read_input()
{
    scanf("%d %d", &n, &m);
    A.resize(n + 1);
    B.resize(m + 1);

    for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
    for (int i = 1; i <= m; ++i) scanf("%d", &B[i]);
}

void find_ans() 
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j - 1] + A[i] * B[j], A[i] * B[j]);
            ans = max(ans, dp[i][j]);
        }
    }

    for (int i = 1, j = B.size() - 1; i < j; ++i, --j) swap(B[i], B[j]);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = max(dp[i - 1][j - 1] + A[i] * B[j], A[i] * B[j]);
            ans = max(ans, dp[i][j]);
        }
    }
}