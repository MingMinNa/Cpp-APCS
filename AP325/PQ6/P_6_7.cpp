#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d070

string str_1, str_2;

void read_input();
int find_ans();


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    printf("%d", find_ans());
}

void read_input()
{
    cin >> str_1 >> str_2;
}

int find_ans()
{
    vector<vector<int>> dp(
        str_1.size() + 1, 
        vector<int>(str_2.size() + 1)
    );

    for (size_t i = 1; i <= str_1.size(); ++i) {
        for (size_t j = 1; j <= str_2.size(); ++j) {

            if (str_1[i - 1] == str_2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[str_1.size()][str_2.size()];
}