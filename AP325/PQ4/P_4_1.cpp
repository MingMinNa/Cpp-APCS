#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d042

int n;
vector<int> vec;

void read_input();
int find_ans(int dollar);


int main()
{
    read_input();
    for (int i = 0; i < n; ++i) {
        printf("%d\n", find_ans(vec[i]));
    }
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

int find_ans(int dollar)
{
    return \
         dollar / 50 + 
        (dollar % 50) / 10 + 
        (dollar % 10) / 5 +
        (dollar % 5);
}