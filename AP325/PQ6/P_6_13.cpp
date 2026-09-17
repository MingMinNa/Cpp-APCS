#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d077

int n, k, ans = 0;
vector<int> vec;

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
    vec.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &vec[i]);
    }
}

void find_ans()
{
    deque<int> dq;
    vector<int> dp(n + 1);

    dp[1] = vec[1];
    dq.push_back(1);
    
    for (int i = 2; i <= n; ++i) {

        if (dq.front() < i - 2 * k - 1) {
            dq.pop_front();
        }

        if (i <= k + 1) dp[i] = vec[i];
        else            dp[i] = vec[i] + dp[dq.front()];

        while (!dq.empty() && dp[dq.back()] >= dp[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    ans = *min_element(dp.begin() + n - k, dp.end());
}