#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d094
// https://zerojudge.tw/ShowProblem?problemid=f166

typedef long long LL;

int n, P, L, R;
vector<int> transmit;
vector<int> step;

void read_input();
LL find_ans();


int main() 
{
    read_input();
    printf("%lld\n", find_ans());
}

void read_input() 
{
    scanf("%d %d %d %d", &n, &P, &L, &R);
    transmit.resize(n);
    step.resize(n, -1);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &transmit[i]);
    }
}

LL find_ans() 
{
    queue<int> q;
    step[0] = 0;
    q.push(0);
    
    // BFS 
    while (!q.empty() && step[P] == -1) {
        
        int next;
        int p = q.front(); q.pop();

        if (p - L >= 0) {

            next = transmit[p - L];
            
            if (next >= 0 && next < n && step[next] == -1) {
                step[next] = step[p] + 1;
                q.push(next);
            }
        }

        if (p + R < n) {

            next = transmit[p + R];

            if (next >= 0 && next < n && step[next] == -1) {
                step[next] = step[p] + 1;
                q.push(next);
            }
        }
    }

    return step[P];
}