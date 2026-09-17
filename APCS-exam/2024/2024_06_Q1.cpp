#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=o076 (1. 特技表演)

int n, ans = 1;
vector<int> h;

void read_input();


int main() 
{
    read_input();
    printf("%d", ans);
}

void read_input() 
{
    scanf("%d", &n);
    h.resize(n + 1, INT_MAX);

    int c = 0;

    for (int i = 1; i <= n; ++i) {

        scanf("%d", &h[i]);

        if (h[i - 1] > h[i]) c ++;
        else                c = 1;
        
        ans = max(ans, c);
    }
}