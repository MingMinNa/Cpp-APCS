#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d038

typedef long long LL;

struct Func {
    LL a, b;
};

int N, m;
LL ans = 0;
vector<LL> x_vec;
vector<Func> func_vec;

void read_input();
void recursive(int func_s, int func_e, int point_s, int point_e);


int main()
{
    read_input();
    recursive(0, N, 0, m);
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &N, &m);
    func_vec.resize(N);
    x_vec.resize(m);

    for (int i = 0; i < N; ++i) {
        scanf("%lld %lld", &func_vec[i].a, &func_vec[i].b);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%lld", &x_vec[i]);
    }

    sort(x_vec.begin(), x_vec.end());
    sort(func_vec.begin(), func_vec.end(), [](const Func &x, const Func &y) {
        return x.a < y.a || (x.a == y.a && x.b < y.b);
    });
}

void recursive(int func_s, int func_e, int point_s, int point_e)
{
    if (point_s >= point_e) return;

    int mid = (point_s + point_e) >> 1;
    LL max_y = LLONG_MIN, f_idx = 0;

    for (int i = func_s; i < func_e; ++i) {
        
        LL y = func_vec[i].a * x_vec[mid] + func_vec[i].b;
        
        if (max_y < y) {
            max_y = y;
            f_idx = i;
        }
    }

    ans += max_y;
    
    recursive(func_s, f_idx + 1, point_s, mid);
    recursive(f_idx, func_e, mid + 1, point_e);
    
    return;
}