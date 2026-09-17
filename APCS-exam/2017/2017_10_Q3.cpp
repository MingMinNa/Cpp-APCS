#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c463 (3. 樹狀圖分析)

typedef long long LL;

int n, r;
LL total_height = 0ll;
vector<vector<int>> children;

void read_input();
LL search(int u);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    search(r);
    cout << r + 1 << endl << total_height;
}

void read_input() 
{
    cin >> n;
    children.resize(n);
    r = (n - 1) * n / 2;

    int t, c;

    for (int i = 0; i < n; ++i) {

        cin >> t;

        for (int j = 0; j < t; ++j) {

            cin >> c;

            r -= (c - 1);
            children[i].push_back(c - 1);
        }
    }
}

LL search(int u) 
{
    if (children[u].size() == 0) {
        return 0ll;
    } 

    LL h = 0;
    
    for (const auto &ch : children[u]) {
        LL t = search(ch);
        h = max(h, t);
    }

    total_height += (h + 1);
    return h + 1;
}