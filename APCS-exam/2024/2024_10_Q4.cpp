#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=o714 (4. 搭到終點)

struct Bus {
    int l, r;
};

int n, m, p;
vector<Bus> routes;
vector<int> prefix;
unordered_map<int, int> ways;

void read_input();
void find_ans();
bool cmp(const Bus &a, const Bus &b);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << ways[m];
}

void read_input()
{
    cin >> n >> m >> p;
    routes.resize(n + 1);
    prefix.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> routes[i].l;
    for (int i = 1; i <= n; i++) cin >> routes[i].r;
}

void find_ans()
{
    sort(routes.begin() + 1, routes.end(), cmp);
    vector<int> ends(n + 1);

    for (int i = 1; i <= n; i++) {
        ends[i] = routes[i].r;
    }

    for (int i = 1; i <= n; i++) {

        int L = routes[i].l, R = routes[i].r;
        int first = lower_bound(ends.begin() + 1, ends.begin() + i, L) - ends.begin();
        int pos = lower_bound(ends.begin() + 1, ends.begin() + i, R) - ends.begin();
        int last = pos - 1, ways_here = 0;

        if (first <= last) {
            ways_here = (prefix[last] - prefix[first - 1] + p) % p;
        }

        if (L == 0) ways_here = (ways_here + 1) % p;

        ways[R]   = (ways[R] + ways_here) % p;
        prefix[i] = (prefix[i - 1] + ways_here) % p;
    }
}

bool cmp(const Bus &a, const Bus &b) 
{
    if (a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}