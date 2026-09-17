#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d099

typedef long long LL;

int n, m;
LL ans = 0;
set<LL> task_set;
vector<LL> w, t, in_deg;
vector<vector<LL>> pre_work, critical;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();

    printf("%lld\n", ans);
    for (const auto &e : task_set) {
        printf("%lld ", e);
    }
}

void read_input() 
{
    scanf("%d %d", &n, &m);

    w.resize(n + 1);
    t.resize(n + 1);
    in_deg.resize(n + 1);
    pre_work.resize(n + 1);
    critical.resize(n + 1);

    LL u, v;

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &w[i]);
    }

    for (int i = 0; i < m; ++i) {

        scanf("%lld %lld", &u, &v);
        
        // task u must be done before start of task v.
        pre_work[u].push_back(v);
        in_deg[v] ++;
    }
}

void find_ans() 
{
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);        
            t[i] = w[i];
            ans = max(ans, w[i]);
        }
    }

    /* Find the minimum finishing time */
    while (!q.empty()) {

        int idx = q.front(); q.pop();

        for (const auto &e : pre_work[idx]) {

            in_deg[e] --;

            if (t[e] == t[idx] + w[e]) {
                critical[e].push_back(idx);
            }
            else if (t[e] < t[idx] + w[e]) {
                critical[e].clear();
                critical[e].push_back(idx);
                t[e] = t[idx] + w[e];
            }

            if (in_deg[e] == 0) {
                q.push(e);
            }

            ans = max(ans, t[e]);
        }
    }

    /* List the critical tasks */
    queue<int> q2;

    for (int i = 1; i <= n; ++i) {
        if (ans == t[i]) q2.push(i);
    }

    while (!q2.empty()) {

        int idx = q2.front(); q2.pop();
        task_set.insert(idx);

        for (const auto &e : critical[idx]) {
            q2.push(e);
        }
        
        critical[idx].clear();
    }
}