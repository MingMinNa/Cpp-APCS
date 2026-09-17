#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d056 (TLE)

typedef long long LL;

struct Point {
    LL x, y;
};

int n, ans = INT_MAX;
vector<Point> vec;

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
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &vec[i].x, &vec[i].y);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    multimap<LL, LL> mm;
    LL min_d = INT_MAX;

    for (int i = 0; i < n; ++i) {

        auto it = mm.lower_bound(vec[i].y - min_d);

        while (it != mm.end() && it->first <= vec[i].y + min_d) {

            if (vec[i].x - (it->second) > min_d) {
                it = mm.erase(it);
                continue;
            }

            min_d = min(
                min_d, vec[i].x - (it->second) + abs(vec[i].y - (it->first))
            );
            ++ it;
        }

        mm.insert({vec[i].y, vec[i].x});
    }

    ans = min_d;
}