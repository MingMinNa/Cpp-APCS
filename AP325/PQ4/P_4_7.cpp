#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d048

typedef long long LL;

int n, t;
LL ans = 0, total = 0;
priority_queue<LL, vector<LL>, greater<LL>> pq;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%lld\n%lld", total, ans);
}

void read_input()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {

        scanf("%d", &t);
        
        total += t;
        pq.push(t);
    }
}

void find_ans()
{
    while (pq.size() > 1) {

        LL t1 = pq.top(); pq.pop();
        LL t2 = pq.top(); pq.pop();
        
        ans += (t1 + t2);
        pq.push(t1 + t2);
    }
}