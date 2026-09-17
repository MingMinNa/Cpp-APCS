#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=j124 (3. 石窟探險)

typedef long long LL;

LL ans = 0;

void traversal(int parent);


int main() 
{
    traversal(0);
    printf("%lld", ans);
}

void traversal(int parent) 
{
    int curr;
    scanf("%d", &curr);
    
    if (curr == 0) return;

    if (curr & 1) {
        traversal(curr);
        traversal(curr);
        traversal(curr);
    }
    else {
        traversal(curr);
        traversal(curr);
    }

    if (parent != 0) {
        ans += abs(curr - parent);
    }
}