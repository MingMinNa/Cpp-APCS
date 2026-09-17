#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f579 (1. 購物車)

int a, b, n, ans_count = 0;

void read_input();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    cout << ans_count;
}

void read_input() 
{
    cin >> a >> b >> n;

    int k;

    for (int i = 0; i < n; ++i) {

        int buy[2] = {0};

        while (cin >> k, k != 0) {
            if      (k ==  a) buy[0] ++;
            else if (k == -a) buy[0] --;
            if      (k ==  b) buy[1] ++;
            else if (k == -b) buy[1] --;
        }

        if (buy[0] > 0 && buy[1] > 0) {
            ans_count ++;
        }
    }
}