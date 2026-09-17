#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d056

typedef long long LL;

struct Point {
    LL x, y;
};

int n;
vector<Point> vec;

void read_input();
LL recursive(int start, int end);


int main()
{
    read_input();
    printf("%lld", recursive(0, n));
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &vec[i].x, &vec[i].y);
    }

    sort(vec.begin(), vec.end(), [](const Point &a, const Point &b) {
        return a.x < b.x;
    });
}

LL recursive(int start, int end)
{
    if (start + 1 == end) 
        return LLONG_MAX;

    if (start + 2 == end) 
        return \
            abs(vec[start].x - vec[start + 1].x) + 
            abs(vec[start].y - vec[start + 1].y);

    int mid = (start + end) >> 1;
    LL left = recursive(start, mid);
    LL right = recursive(mid, end);
    LL min_L1 = min(left, right);
    
    int i = start - 1, j = mid;

    for (int jump = max((mid - start) >> 1, 1); jump >= 1; jump >>= 1) {
        while (i + jump < mid && vec[mid].x - vec[i + jump].x >= min_L1) {
            i += jump;
        }
    }

    i ++;

    for (; i < mid && j < end; ++j) {

        for (int k = i; k < mid; ++k) {
            min_L1 = min(min_L1, abs(vec[k].x - vec[j].x) + abs(vec[k].y - vec[j].y));
        }

        while (i < mid && vec[j].x - vec[i].x >= min_L1) {
            ++i;
        }
    }
    
    return min_L1;
}