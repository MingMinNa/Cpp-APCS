#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d025

int N, ans = 0, root = 0;
queue<int> q;
vector<int> parent, height, degree;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%d\n%d", root, ans);
}

void read_input()
{
    scanf("%d", &N);
    parent.resize(N);
    degree.resize(N);
    height.resize(N);

    int k, c;

    for (int i = 0; i < N; ++i) {

        scanf("%d", &k);
        degree[i] = k;

        if (k == 0) {
            q.push(i);
            height[i] = 0;
            continue;
        }

        for (int j = 0; j < k; ++j) {
            scanf("%d", &c);
            parent[c - 1] = i;
        }
    }
}

void find_ans()
{
    int c, p;
    
    while (!q.empty()) {
        
        c = q.front(); 
        q.pop();

        // the last one is root (1-index)
        root = c + 1;
        ans += height[c];

        p = parent[c];
        height[p] = max(height[p], height[c] + 1);
        degree[p] --;

        if (degree[p] == 0) {
            q.push(p);
        }
    }
}