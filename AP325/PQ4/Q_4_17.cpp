#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d058

typedef long long LL;

struct Homework {
    int t, d;
};

int n, t;
vector<Homework> vec;

void read_input();
bool find_ans();


int main()
{
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        read_input();
        printf(find_ans() ? "yes\n" : "no\n");
    }
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].t);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].d);
    }
}

bool find_ans()
{
    sort(vec.begin(), vec.end(), [](const Homework &a, const Homework &b) {
        return a.d < b.d || (a.d == b.d && a.t < b.t);
    });

    LL end = 0;

    for (int i = 0; i < n; ++i) {
        
        end += vec[i].t;

        if (end > vec[i].d) 
            return false;
    }

    return true;
}