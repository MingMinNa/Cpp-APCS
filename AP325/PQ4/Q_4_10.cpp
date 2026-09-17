#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d054

typedef long long LL;

int n, m;
LL ans = 0;
vector<LL> vec;

void read_input();
void find_ans();
bool check(LL F);


int main()
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &n, &m);
    vec.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &vec[i]);
        vec[i] += vec[i - 1];
    }
}

void find_ans()
{
    LL min_F = 1, max_F = vec[n - 1];

    for (LL jump = (max_F - min_F) >> 1; jump >= 1; jump >>= 1) {
        while (!check(ans + jump)) {
            ans += jump;
        }
    }

    ans ++;
}

bool check(LL F)
{
    int curr = 1;

    for (int i = 0; i <= m; ++i) {
        
        auto it = upper_bound(vec.begin(), vec.end(), vec[curr - 1] + F);

        if (it == vec.end()) return true;
        curr = it - vec.begin();
    }

    return false;
}