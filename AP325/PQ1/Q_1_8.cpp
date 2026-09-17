#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d007

typedef long long LL;

int n, P;
LL best = 0;
vector<int> nums;

void read_input();
void recursive_sum(int index, LL sum);


int main() 
{
    read_input();
    recursive_sum(0, 0);
    printf("%lld", best);
}

void read_input()
{
    scanf("%d %d", &n, &P);
    nums.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
}

void recursive_sum(int index, LL sum) 
{
    if (index >= n) {
        best = max(best, sum);
        return;
    }

    recursive_sum(index + 1, sum);

    if (sum + nums[index] <= P) {
        recursive_sum(index + 1, sum + nums[index]);
    }
}