#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=q838 (3. 貪心闖關)

typedef long long LL;

int n, t;
LL ans = 0;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
    printf("%lld\n", ans);
}

void read_input()
{
    scanf("%d %d", &n, &t);
}

void find_ans()
{
    LL bags = 0;
    stack<LL> stk;

    for (int i = 0; i < n; ++i) {
        
        scanf("%lld", &bags);

        while (!stk.empty() && stk.top() <= bags) {
            ans += stk.top();
            bags += stk.top();
            stk.pop();
        }

        if (bags <= t) {
            stk.push(bags);
        }
    }

    while (!stk.empty() && stk.top() <= t) {
        ans += stk.top();
        stk.pop();
    }
}