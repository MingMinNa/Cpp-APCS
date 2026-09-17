#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d003

typedef long long LL;

int N, L;
vector<int> vec;

void read_input();
LL cut(int left, int right);


int main()
{
    read_input();
    printf("%lld", cut(0, N + 1));
}

void read_input()
{
    scanf("%d %d", &N, &L);
    vec.resize(N + 2);

    vec[0] = 0;
    vec[N + 1] = L;
 
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &vec[i]);
    }
}

LL cut(int left, int right)
{
    if (left + 1 >= right) return 0;

    LL res = left + 1, len = vec[right] - vec[left];

    for (int jump = (right - left) >> 1; jump >= 1; jump >>= 1) {
        while (
            res + jump < right && 
            vec[res + jump] - vec[left] < vec[right] - vec[res + jump]
        ) {
            res += jump;
        }
    }

    if (vec[right] - vec[res + 1] > vec[res] - vec[left]) res ++;

    return cut(left, res) + cut(res, right) + len;
}