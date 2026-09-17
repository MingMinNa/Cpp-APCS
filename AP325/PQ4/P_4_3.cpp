#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d044

typedef long long LL;

int n;
LL ans = 0;
vector<int> vec;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end());
    
    for (int i = 0; i < n; ++i) {
        ans += 1ll * (n - i) * vec[i];
    }
}