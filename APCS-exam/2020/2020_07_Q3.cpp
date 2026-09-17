#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f581 (3. 圓環出口)

typedef long long LL;

int n, m, pos; 
vector<LL> p, q;

void read_input();
void find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << pos - 1;
}

void read_input() 
{
    cin >> n >> m;
    p.resize(n + 1);
    q.resize(m);

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] += p[i - 1];
    }

    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }
}

void find_ans() 
{
    pos = 1;
    int index;

    for (int i = 0; i < m; ++i) {
        
        if (p[n] - p[pos - 1] >= q[i]) {
            index = lower_bound(p.begin() + pos, p.end(), q[i] + p[pos - 1]) - p.begin(); 
            pos = (index == n) ? (1) : (index + 1);
            continue;
        }
        else {
            q[i] -= (p[n] - p[pos - 1]);
            q[i] %= p[n];
            pos = 1;
        }

        index = lower_bound(p.begin() + pos, p.end(), q[i]) - p.begin();
        pos = (index == n) ? (1) : (index + 1);
    }
}