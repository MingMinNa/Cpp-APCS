#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d013

typedef long long LL;

LL x = 0, y, p;
string input_x;

void read_input();
LL fast_exp(int base, int pow);


int main() 
{
    read_input();
    printf("%lld", fast_exp(x, y));
}

void read_input()
{
    cin >> input_x >> y >> p;
    
    for (const char &c : input_x) {
        x = x * 10 + c - '0';
        x %= p;
    }
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