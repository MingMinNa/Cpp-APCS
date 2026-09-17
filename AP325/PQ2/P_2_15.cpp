#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d024

int n, m, ans = -1;
vector<int> p, Q;

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
    scanf("%d %d", &n, &m);
    p.resize(n + 1);
    Q.resize(m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
        p[i] += p[i - 1];
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d", &Q[i]);
    }
}

void find_ans()
{
    int curr = 0;

    for (int i = 0; i < m; ++i) {

        int target = Q[i];

        if (p[n] - p[curr] < target) {
            target -= (p[n] - p[curr]);
            curr = 0;
        }

        // find p[i] - p[curr] >= target
        // p[i] >= target + p[curr]
        auto it = lower_bound(p.begin() + curr, p.end(), target + p[curr]);
        curr = it - p.begin();
    }
    
    ans = curr;
}