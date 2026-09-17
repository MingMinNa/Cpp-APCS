#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d012

typedef long long LL;

int x, y, p;

void read_input();
LL fast_exp(int base, int pow);


int main() 
{
    read_input();
    printf("%lld", fast_exp(x, y));
}

void read_input()
{
    scanf("%d %d %d", &x, &y, &p);
}

LL fast_exp(int base, int pow) 
{
    if (pow == 0) return 1ll;
    
    LL ret = fast_exp(base, pow >> 1);
    ret = (ret * ret) % p;

    if (pow & 1) {
        ret = (ret * base) % p;
    }

    return ret;
}