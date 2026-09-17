#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d061

struct Segment{
    int s, t;
};

int n, x, y, ans = -1;
vector<Segment> vec;

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
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &vec[i].s, &vec[i].t);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Segment &a, const Segment &b) {
        return a.s < b.s;
    });

    int curr = x, i = 0, c = 0;

    while (curr < y) {

        int best = curr;

        while (i < n && vec[i].s <= curr) {
            best = max(best, vec[i].t);
            i ++;
        }

        if (best == curr) return;
        curr = best;
        c ++;
    }
    
    ans = c;
}