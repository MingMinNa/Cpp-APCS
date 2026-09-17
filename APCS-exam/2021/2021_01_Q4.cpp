#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f608 (4. 飛黃騰達)

int n, ans = 0;
vector<pair<int, int>> vec;

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
        scanf("%d %d", &vec[i].first, &vec[i].second);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end());
    vector<int> dp;

    for (int i = 0; i < n; ++i) {
        
        int y = vec[i].second;
        auto it = upper_bound(dp.begin(), dp.end(), y);

        if (it == dp.end()) dp.push_back(y);
        else                *it = y;
    }

    ans = dp.size();
}