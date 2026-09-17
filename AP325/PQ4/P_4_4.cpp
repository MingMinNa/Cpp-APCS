#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d045

struct Event {
    int s, t;
};

int n, ans = 0;
vector<Event> vec;

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
        scanf("%d %d", &vec[i].s, &vec[i].t);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Event &e1, const Event &e2) {
        return e1.t < e2.t || (e1.t == e2.t && e1.s > e2.s);
    });

    int t = -1;
    
    for (int i = 0; i < n; ++i) {
        if (t < vec[i].s) {
            t = vec[i].t;
            ans ++;
        } 
    }
}