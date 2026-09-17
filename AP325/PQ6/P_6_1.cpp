#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d066

int n, ans = 0;
vector<int> vec;

void read_input();


int main()
{
    read_input();
    printf("%d", ans);
}

void read_input() 
{
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }

    for (int i = 2; i < n; ++i) {
        vec[i] += min(vec[i - 1], vec[i - 2]);
    }
    
    ans = vec[n - 1];
}