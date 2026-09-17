#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d018

typedef long long LL;

int n, P;
LL ans = 0;
vector<int> arr;
unordered_map<int, int> left_count;  // [0, n / 2)
unordered_map<int, int> right_count; // [n / 2, n)

void read_input();
void find_ans();
void recursive(int curr, int end, LL prod, unordered_map<int, int> &prod_count);
LL fast_exp(LL base, LL pow);


int main()
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &n, &P);
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
}

void find_ans()
{
    recursive(0, n / 2, 1, left_count);
    recursive(n / 2, n, 1, right_count);

    for (auto it = left_count.begin(); it != left_count.end(); ++it) {
        LL inverse = fast_exp(it->first, P - 2);
        ans += (it->second) * right_count[inverse]; 
    }

    ans --; // delete the case that all elements are unselected
}

void recursive(int curr, int end, LL prod, unordered_map<int, int> &prod_count)
{
    if (curr >= end) {
        prod_count[prod] ++;
        return;
    }

    recursive(curr + 1, end, prod, prod_count);
    recursive(curr + 1, end, (prod * arr[curr]) % P, prod_count);
}

LL fast_exp(LL base, LL pow)
{
    if (pow == 0)
        return 1ll;
    
    LL ret = fast_exp(base, pow >> 1);
    ret = (ret * ret) % P;

    if (pow & 1) {
        ret = (ret * base) % P;
    }

    return ret;
}