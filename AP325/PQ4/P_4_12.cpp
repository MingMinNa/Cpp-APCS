#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d051

int n, ans = 0;

void read_input();


int main()
{
    read_input();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d", &n);

    int t, min_val = INT_MAX;

    for (int i = 0; i < n; ++i) {
        
        scanf("%d", &t);

        min_val = min(min_val, t);
        ans = max(ans, t - min_val);
    }
}