#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d059

typedef long long LL;

int n, D, ans = 0;
vector<int> vec;

void read_input();
void find_ans();
bool check(int m);


int main() 
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d %d", &n, &D);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

void find_ans()
{
    int min_m = 1;
    int max_m = n;

    for (int jump = (max_m - min_m) >> 1; jump >= 1; jump >>= 1) {
        while (!check(ans + jump)) {
            ans += jump;
        }
    }

    ans ++;
}

bool check(int m)
{
    priority_queue<LL, vector<LL>, greater<LL>> pq;

    for (int i = 0; i < m; ++i) {
        pq.push(0);
    }

    for (int i = 0; i < n; ++i) {
        
        LL t = pq.top(); pq.pop();
        
        if (t + vec[i] > D) return false;
        pq.push(t + vec[i]);
    }

    return true;
}