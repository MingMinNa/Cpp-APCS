#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=g595 (1. 修補圍籬)

int n, ans = 0;
vector<int> h;

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
    scanf("%d", &n);
    h.resize(n + 2, INT_MAX);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }
}

void find_ans() 
{
    for (int i = 1; i <= n; ++i) {
        if (h[i] > 0) continue;
        ans += min(h[i - 1], h[i + 1]);
    }
}