#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d050

typedef long long LL;

struct Segment {
    int s, e;
};

int N;
LL ans = 0;
vector<Segment> vec;

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
    scanf("%d", &N);
    vec.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &vec[i].s, &vec[i].e);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Segment &a, const Segment &b) {
        return a.s < b.s || (a.s == b.s && a.e < b.e);
    });

    int end = -1;

    for (int i = 0; i < N; ++i) {
        
        if (vec[i].s > end) {
            ans += (vec[i].e - vec[i].s);
            end = vec[i].e;
        }
        else if (vec[i].e > end) {
            ans += (vec[i].e - end);
            end = vec[i].e;
        }
    }
}