#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d060

struct Party {
   int m, s, t;
};

int n, ans = 0;
vector<Party> vec;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &vec[i].m, &vec[i].s, &vec[i].t);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Party &a, const Party &b) {
        return a.s < b.s;
    });

    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
    > pq;

    int curr = 0;

    for (int i = 0; i < n; ++i) {

        curr += vec[i].m;
        
        while (!pq.empty() && pq.top().first < vec[i].s) {
            curr -= pq.top().second;
            pq.pop();
        }

        pq.push({vec[i].t, vec[i].m});
        ans = max(ans, curr);
    }
}