#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d053

typedef long long LL;

int n, m;
LL ans = 0;
vector<int> vec;
priority_queue<LL, vector<LL>, greater<LL>> pq;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &n, &m);
    vec.resize(n);

    for (int i = 0; i < m; ++i) {
        pq.push(0);
    }
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

void find_ans()
{
    for (int i = 0; i < n; ++i) {
        LL t = pq.top(); pq.pop();
        ans = max(ans, t + vec[i]);
        pq.push(t + vec[i]);
    }
}