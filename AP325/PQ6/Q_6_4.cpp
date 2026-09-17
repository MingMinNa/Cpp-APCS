#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d072

typedef long long LL;

int n, t;
LL ans = 0;
vector<pair<LL, LL>> vec;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &n, &t);
    vec.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld", &vec[i].first, &vec[i].second);
    }
}

void find_ans()
{
    vector<pair<LL, LL>> dp(n + 1);
    vec[0].first = vec[0].second = t;

    for (int i = 1; i <= n; ++i) {
        
        // first
        dp[i].first = min(
            dp[i - 1].first + abs(vec[i].first - vec[i - 1].first),
            dp[i - 1].second + abs(vec[i].first - vec[i - 1].second)
        );

        // second
        dp[i].second = min(
            dp[i - 1].first + abs(vec[i].second - vec[i - 1].first),
            dp[i - 1].second + abs(vec[i].second - vec[i - 1].second)
        );
    }

    ans = min(dp[n].first, dp[n].second);
}