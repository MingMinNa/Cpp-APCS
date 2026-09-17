#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d071

struct Item {
    int v, w;
};

int n, W;
vector<Item> vec;

void read_input();
int find_ans();


int main()
{
    read_input();
    printf("%d", find_ans());
}

void read_input()
{
    scanf("%d %d", &n, &W);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].w);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].v);
    }
}

int find_ans()
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    for (int i = 1; i <= n; ++i) {

        int j = 0;
        
        for (; j < min(vec[i - 1].w, W + 1); ++j) {
            dp[i][j] = dp[i - 1][j];
        }
        
        for (; j <= W; ++j) {
            dp[i][j] = max(
                dp[i - 1][j], 
                dp[i - 1][j - vec[i - 1].w] + vec[i - 1].v
            );
        }
    }

    return dp[n][W];
}