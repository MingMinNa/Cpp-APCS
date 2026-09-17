#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d004

typedef long long LL;

int N, K;
vector<int> vec;

void read_input();
LL cut(int left, int right, int level);


int main()
{
    read_input();
    printf("%lld", cut(0, N - 1, 0));
}

void read_input()
{
    scanf("%d %d", &N, &K);
    vec.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &vec[i]);
    }
}

LL cut(int left, int right, int level)
{
    if (level >= K)        return 0ll;
    if (left + 1 >= right) return 0ll;

    int best_pos = left + 1;
    LL best_value = (-1) * vec[left]; 
    LL interval_sum = vec[left];

    for (int i = left + 1; i <= right; ++i) {
        best_value += 1ll * (i - best_pos) * vec[i];
        interval_sum += vec[i];
    }

    for (int i = best_pos + 1; i < right; ++i) {
        if (abs(best_value) > abs(best_value - interval_sum * (i - best_pos))) {
            best_value -= interval_sum * (i - best_pos);
            best_pos = i;
        }
    }
    
    return 
        cut(left, best_pos - 1, level + 1)  + \
        cut(best_pos + 1, right, level + 1) + \
        vec[best_pos];
}

