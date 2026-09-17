#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d080 (4. 階梯數字)

typedef long long LL;

string n;

void read_input();
LL find_ans();


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    printf("%lld", find_ans());
}

void read_input()
{
    cin >> n;

    for (size_t i = 0; i < n.size(); ++i) {
        n[i] -= '0';
    }
}

LL find_ans()
{
    LL ans = 0;
    vector<vector<LL>> dp(20, vector<LL>(10));
    
    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (size_t i = 2; i <= n.size(); ++i) { 

        dp[i][9] = dp[i - 1][9]; 
        
        for (int j = 8; j >= 0; --j) {
            dp[i][j] = dp[i][j + 1] + dp[i - 1][j];
        }
    }

    for (int i = 0; i < n[0]; ++i) {
        ans += dp[n.size()][i];
    }

    size_t i;

    for (i = 1; i < n.size(); ++i) {
        
        if (n[i] < n[i - 1]) break;

        for (int j = n[i - 1]; j < n[i]; ++j) {
            ans += dp[n.size() - i][j];
        }
    }

    // n is also a stepping number
    if (i == n.size()) ans ++;

    return ans;
}