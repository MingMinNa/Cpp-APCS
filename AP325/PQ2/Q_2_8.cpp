#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d017

typedef long long LL;

LL n, P;
vector<LL> nums;

void read_input();
LL fast_exp(LL base, LL pow);


int main() 
{
    read_input();
    for (int i = 0; i < n; ++i) {
        printf("%lld ", fast_exp(nums[i] % P, P - 2));
    }
}

void read_input() 
{
    scanf("%lld %lld", &n, &P);
    nums.resize(n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &nums[i]);
    }
}

LL fast_exp(LL base, LL pow) 
{
    if (pow == 0) return 1ll;
     
    LL ret = fast_exp(base, pow >> 1);
    ret = (ret * ret) % P;

    if (pow & 1) {
        ret = (ret * base) % P;
    }
    
    return ret;
}