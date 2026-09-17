#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d057

typedef long long LL;

struct Task {
    int t, d;
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
        scanf("%d", &vec[i].d);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Task &a, const Task &b) {
        return a.t < b.t || (a.t == b.t && a.d < b.d);
    });

    LL end = 0;
    
    for (int i = 0; i < n; ++i) {
        end += vec[i].t;
        ans += (vec[i].d - end);
    }
}