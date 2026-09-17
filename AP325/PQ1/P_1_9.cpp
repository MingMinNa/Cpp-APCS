#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;
LL ans = 0;
vector<int> pos;

void read_input();
void recursive(int curr);


int main()
{
    read_input();
    recursive(0);
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d", &n);
    pos.resize(n);
}

void recursive(int curr)
{
    if (curr == n) {
        ans ++;
        return;
    }

    vector<char> valid_r(n, 1);

    for (int i = 0; i < curr; ++i) {

        valid_r[pos[i]] = 0;

        if (pos[i] + curr - i <  n) valid_r[pos[i] + curr - i] = 0;
        if (pos[i] + i - curr >= 0) valid_r[pos[i] + i - curr] = 0;
    }

    for (int i = 0; i < n; ++i) {

        if (!valid_r[i]) continue;

        pos[curr] = i;
        recursive(curr + 1);
    }
}