#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d087

typedef long long LL;

int N;
multiset<int> S;

void read_input();


int main() 
{
    read_input();
    printf("%d\n", (int)S.size());
}

void read_input() 
{
    scanf("%d", &N);

    int s, t;

    for (int i = 0; i < N; ++i) {
        
        scanf("%d %d", &s, &t);
        
        S.insert(s);
        auto it = S.upper_bound(t);
        
        if (it != S.end()) {
            S.erase(it);
        }
    }
}