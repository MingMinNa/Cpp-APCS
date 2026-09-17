#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d067

int n;
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
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

int find_ans() 
{
    if      (n == 0) return 0;
    else if (n == 1) return vec[0];

    vector<int> dp(n);
    dp[0] = vec[0];
    dp[1] = max(vec[0], vec[1]);

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 2] + vec[i], dp[i - 1]);
    }

    return dp[n - 1];
}