#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=m934 (4. 合併成本)

int n;
vector<vector<int>> cost, value;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%d", cost[1][n]);
}

void read_input()
{
    scanf("%d", &n);
    cost.resize(n + 2, vector<int>(n + 2));
    value.resize(n + 2, vector<int>(n + 2));

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &value[i][i]);
        cost[i][i] = 0;
    }
}

void find_ans()
{
    for (int len = 1; len < n; ++len) {
        for (int i = 1; i <= n - len; ++i) {

            int j = i + len;
            cost[i][j] = INT_MAX;

            for (int k = i; k <= j; ++k) {

                int s = cost[i][k] + cost[k + 1][j] + abs(value[i][k] - value[k + 1][j]);
                
                cost[i][j] = min(s, cost[i][j]);
                value[i][j] = value[i][k] + value[k + 1][j];
            }
        }
    }
}