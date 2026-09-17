#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d010

int n, t;
set<int> distinct_nums;

void read_input();


int main()
{
    read_input();
    printf("%ld\n", distinct_nums.size());
    for (const auto &e : distinct_nums) {
        printf("%d ", e);
    }
}

void read_input()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        distinct_nums.insert(t);
    }
}