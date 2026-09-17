#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d014

#define MOD_P(n) ((n) % p)

typedef long long LL;

struct Matrix {
    LL a11, a12;
    LL a21, a22;
};

const int p = 1e9 + 7;

int n;

int fast_fib(int n);
Matrix fast_mat_mul(int pow);


int main() 
{
    while (scanf("%d", &n), n != -1) {
        printf("%d\n", fast_fib(n));
    }
}

int fast_fib(int n) 
{
    if (n == 0) return 0;
    return fast_mat_mul(n - 1).a11;
}

Matrix fast_mat_mul(int pow) 
{
    if (pow == 0) {
        return {
            .a11 = 1, .a12 = 0,
            .a21 = 0, .a22 = 1
        };
    }

    Matrix ret = fast_mat_mul(pow / 2);
    
    ret = {
        .a11 = MOD_P(MOD_P(ret.a11 * ret.a11) + MOD_P(ret.a12 * ret.a21)),
        .a12 = MOD_P(MOD_P(ret.a11 * ret.a12) + MOD_P(ret.a12 * ret.a22)),
        .a21 = MOD_P(MOD_P(ret.a21 * ret.a11) + MOD_P(ret.a22 * ret.a21)),
        .a22 = MOD_P(MOD_P(ret.a21 * ret.a12) + MOD_P(ret.a22 * ret.a22)),
    };

    if (pow & 1) {
        ret = {
            .a11 = MOD_P(ret.a11 + ret.a12),
            .a12 = ret.a11,
            .a21 = MOD_P(ret.a21 + ret.a22),
            .a22 = ret.a21,
        };
    }

    return ret;
}