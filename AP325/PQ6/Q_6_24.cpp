#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d088

typedef long long LL;

int n;
vector<LL> height, value, dp, dominated, best_left;

void read_input();
LL find_ans();


int main()
{
    read_input();
    printf("%lld", find_ans());
}

void read_input()
{
    scanf("%d", &n);
    dp.resize(n + 1);
    value.resize(n + 1);
    height.resize(n + 1);
    dominated.resize(n + 1);
    best_left.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &height[i]);
    }
    
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &value[i]);
    }
}

LL find_ans()
{
    stack<int> dominate_stk;
    stack<int> left_high_stk;

    for (int i = 1; i <= n; ++i) {

        while (!dominate_stk.empty() && height[dominate_stk.top()] < height[i]) {
            int top = dominate_stk.top();
            dominated[i] = max({dominated[i], dominated[top], dp[top]});
            dominate_stk.pop();
        }

        while (!left_high_stk.empty() && height[left_high_stk.top()] <= height[i]) {
            left_high_stk.pop();
        }

        // height[i] is the highest 
        if (dominate_stk.empty()) {
            dp[i] = value[i];
            best_left[i] = dominated[i];
        } 
        else {
            LL from_left = 0;
            if (!left_high_stk.empty()) {
                from_left = best_left[left_high_stk.top()];
            }

            dp[i] = from_left + value[i];

            // if dominate_stk.top() == i - 1, best_left[dominate_stk.top()] > dominated[i];
            // otherwise, best_left[dominate_stk.top()] < dominated[i]
            best_left[i] = max(best_left[dominate_stk.top()], dominated[i]);
        }

        dominate_stk.push(i);
        left_high_stk.push(i);
    }

    return *max_element(dp.begin() + 1, dp.end());
}