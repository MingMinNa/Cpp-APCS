#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d022

#define MOD_P(x) ((x) % P)

typedef long long LL;

const LL P = 1e9 + 9;

LL x, y, n;

void read_input();
pair<LL, LL> fast_exp(pair<LL, LL> base, LL pow);


int main()
{
    read_input();
    pair<LL, LL> ans = fast_exp({x, y}, n);
    printf("%lld %lld", ans.first, ans.second);
}

void read_input()
{
    scanf("%lld %lld %lld", &x, &y, &n);
}

pair<LL, LL> fast_exp(pair<LL, LL> base, LL pow)
{
    if (pow == 0) return {1, 0};

    pair<LL, LL> ret = fast_exp(base, pow >> 1);
    
    ret = {
        MOD_P(MOD_P(ret.first * ret.first) + 2ll * MOD_P(ret.second * ret.second)),
        MOD_P(2ll * MOD_P(ret.first * ret.second))
    };

    if (pow & 1) {
        ret = {
            MOD_P(MOD_P(ret.first * base.first) + 2ll * MOD_P(ret.second * base.second)),
            MOD_P(MOD_P(ret.first * base.second) + MOD_P(ret.second * base.first)),
        };
    }

    return ret;
}