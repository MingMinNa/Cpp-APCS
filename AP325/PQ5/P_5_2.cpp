#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d052

typedef long long LL;

int n, ans = 0;
vector<LL> vec;

void read_input();
LL recursive(int start, int end);


int main()
{
    read_input();
    printf("%lld", recursive(1, n + 1));
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &vec[i]);
        vec[i] += vec[i - 1];
    }
}

LL recursive(int start, int end) 
{
    if (start + 1 == end) 
        return max(0ll, vec[start] - vec[start - 1]);

    int mid = (end + start) >> 1;
    LL left = recursive(start, mid);
    LL right = recursive(mid, end);

    LL left_min = 0, ret = 0;
    
    for (int i = start; i < mid; ++i) {
        left_min = min(left_min, vec[i]);
    }

    for (int i = mid; i < end; ++i) {
        ret = max(vec[i] - left_min, ret);
    }

    return max(ret, max(left, right));
}