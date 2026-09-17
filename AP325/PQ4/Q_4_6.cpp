#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d047

typedef long long LL;

struct Item {
    int w, f;
};

int n;
LL ans = 0;
vector<Item> vec;

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
        scanf("%d", &vec[i].w);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].f);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Item &a, const Item &b) {
        return a.f * b.w > a.w * b.f;
    });

    LL t = 0;
    
    for (int i = 0; i < n; ++i) {
        ans += t * vec[i].f;
        t += vec[i].w;
    }
}