#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=g278 (4. 美食博覽會)

int n, k, ans = 0;
vector<int> arr, lim_vec;
vector<vector<int>> dp;
unordered_map<int, int> M;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d %d", &n, &k);
    arr.resize(n + 1);
    lim_vec.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
}

void find_ans()
{
    int max_lim = 1;

    for (int i = 1; i <= n; ++i) {
        lim_vec[i] = M[arr[i]] + 1;
        max_lim = lim_vec[i] = max(max_lim, lim_vec[i]);
        M[arr[i]] = i;
    }

    dp.assign(k + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max(
                dp[i][j - 1],
                dp[i - 1][lim_vec[j] - 1] + (j - lim_vec[j] + 1)
            );
        }
    }

    ans = dp[k][n];
}