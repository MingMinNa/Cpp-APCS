#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d019

typedef long long LL;

LL n, P, ans = 0;
vector<LL> arr;
set<LL> left_sum, right_sum;

void read_input();
void find_ans();
void recursive(int curr, int end, LL sum, set<LL> &sum_set);


int main() 
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%lld %lld", &n, &P);
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
    }
}

void find_ans()
{
    recursive(0, n / 2, 0, left_sum);
    recursive(n / 2, n, 0, right_sum);

    for (auto it = left_sum.begin(); it != left_sum.end(); ++it) {

        auto it2 = right_sum.upper_bound(P - *it);
        if (it2 == right_sum.begin()) continue;

        it2 --;
        ans = max(ans, *it + *it2);
    }
}

void recursive(int curr, int end, LL sum, set<LL> &sum_set) 
{
    if (curr >= end) {
        sum_set.insert(sum);
        return;
    }

    recursive(curr + 1, end, sum, sum_set);

    if (sum + arr[curr] <= P) {
        recursive(curr + 1, end, sum + arr[curr], sum_set);
    }
}