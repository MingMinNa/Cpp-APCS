#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f605 (1. 購買力)

int n, d, ans_count = 0, ans_sum = 0;

void read_input();


int main() 
{
    read_input();
    printf("%d %d", ans_count, ans_sum);
}

void read_input() 
{
    scanf("%d %d", &n, &d);
    
    int maxi, mini, s, a;

    for (int i = 0; i < n; ++i) {

        maxi = INT_MIN, mini = INT_MAX, s = 0;

        for (int j = 0; j < 3; ++j) {
            
            scanf("%d", &a);

            s += a;
            maxi = max(maxi, a);
            mini = min(mini, a);
        }

        if (maxi - mini >= d) {
            ans_sum += s / 3;
            ans_count ++;
        }
    }
}