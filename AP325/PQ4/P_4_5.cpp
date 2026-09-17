#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d046

typedef long long LL;

struct Task {
    int t, w;
};

int n;
LL ans = 0;
vector<Task> vec;

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
        scanf("%d", &vec[i].t);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].w);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Task &a, const Task &b) {
        return a.t * b.w < a.w * b.t;
    });

    LL t = 0;
    
    for (int i = 0; i < n; ++i) {
        t += vec[i].t;
        ans += t * vec[i].w;
    }
}