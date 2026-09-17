#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=h081 (1. 程式交易)

int n, D;
vector<int> a;

void read_input();
int find_ans();


int main() 
{
    read_input();
    printf("%d", find_ans());
}

void read_input() 
{
    scanf("%d %d", &n, &D);
    a.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}

int find_ans() 
{
    bool buy = true;
    int x = a[0], ans = 0;

    for (int i = 1; i < n; ++i) {

        if (buy && a[i] >= x + D) {
            buy = false;
            ans += a[i] - x;
            x = a[i];
        }
        else if (!buy && a[i] <= x - D) {
            buy = true;
            x = a[i];
        }
    }

    return ans;
}