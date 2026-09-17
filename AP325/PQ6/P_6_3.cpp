#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d068

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
    else if (n == 2) return min(vec[0], vec[1]);

    vector<int> dp(n);
    dp[0] = vec[0];
    dp[1] = vec[1];
    dp[2] = vec[2] + min(dp[0], dp[1]);

    for (int i = 3; i < n; ++i) {
        dp[i] = vec[i] + min(dp[i - 3], min(dp[i - 2], dp[i - 1]));
    }

    return min(dp[n - 1], dp[n - 2]);
}