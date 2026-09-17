#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d005

typedef long long LL;

int n, i = -1;
string S;

void read_input();
LL count_pixels_1(int length);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    printf("%lld", count_pixels_1(n));
}

void read_input()
{
    cin >> S;
    cin >> n;
}

LL count_pixels_1(int length)
{
    i ++;
    
    if      (i >= S.size() || S[i] == '0') return 0ll;
    else if (S[i] == '1')                  return length * length;

    LL pixels_1 = 0;

    for (int i = 0; i < 4; ++i) {
        pixels_1 += count_pixels_1(length >> 1);
    }

    return pixels_1;
}

