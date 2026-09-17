#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d107

int n, total = 0;
vector<int> parent, deg, mark;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%d\n", total);
}

void read_input()
{
    scanf("%d", &n);

    parent.resize(n);
    deg.resize(n, 0);
    mark.resize(n, 0);

    for (int i = 1; i < n; ++i) {
        scanf("%d", &parent[i]);
        deg[parent[i]] ++;
    }
}

void find_ans()
{
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) q.push(i);
    }

    int visited = 0;

    while (!q.empty()) {

        int v = q.front(); q.pop();
        visited ++;

        if (v == 0) break;

        if (mark[v] == 0) {
            total ++;
            mark[parent[v]] = 1;
        }

        deg[parent[v]] --;
        
        if (deg[parent[v]] == 0) {
            q.push(parent[v]);
        }
    }

    if (mark[0] == 0) total ++; // if root is chosen
}