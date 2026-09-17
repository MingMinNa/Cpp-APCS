#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d028

typedef long long LL;

int N;
LL ans = 0;

void read_input();


int main()
{
    read_input();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d", &N);

    int h;
    stack<pair<int, int>> h_stk;
    
    h_stk.push({0, INT_MAX});

    for (int i = 1; i <= N; ++i) {

        scanf("%d", &h);

        while (!h_stk.empty() && h_stk.top().second <= h) {
            h_stk.pop();
        }

        ans += (i - h_stk.top().first);
        h_stk.push({i, h});
    }
}