#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d079

int n, L;
vector<int> vec;

void read_input();
int find_ans();


int main()
{
    read_input();
    printf("%d", find_ans());
}

void read_input()
{
    scanf("%d %d", &n, &L);
    vec.resize(n + 2);

    vec[0] = 0;
    vec[n + 1] = L;

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &vec[i]);
    }
}

int find_ans()
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int len = 2; len <= n + 1; ++len) {
        for (int i = 0; i + len <= n + 1; ++i) {

            int j = i + len, cost = INT_MAX;
            
            for (int k = i + 1; k < j; ++k) {
                cost = min(cost, dp[i][k] + dp[k][j]);
            }
            
            dp[i][j] = cost + vec[j] - vec[i];
        }
    }

    return dp[0][n + 1];
}