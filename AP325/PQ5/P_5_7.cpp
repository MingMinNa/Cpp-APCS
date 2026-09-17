#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d065

typedef long long LL;

int n;
vector<LL> vec;

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
        scanf("%lld", &vec[i]);
    }
}

LL recursive(int start, int end)
{
    if (start >= end)     return 0;
    if (start + 1 == end) return vec[start];

    int mid = (start + end) >> 1;
    LL left = recursive(start, mid);
    LL right = recursive(mid + 1, end); 
    LL ret = max(left, right);

    LL i = mid, j = mid, h = vec[mid];

    while (start <= i || j < end) {

        if      (i < start) h = vec[j];
        else if (j >= end ) h = vec[i];
        else                h = max(vec[i], vec[j]);

        while (start <= i && vec[i] >= h) --i;
        while (j < end && vec[j] >= h)    ++j;
        ret = max(ret, (j - i - 1) * h);
    }
    
    return ret;
}