#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=h083 (3. 數位占卜)

int m, ans = 0;
vector<string> strs;
unordered_set<string> S;

void read_input();
void find_ans();


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << ans;
}

void read_input()
{
    cin >> m;
    strs.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> strs[i];
        S.insert(strs[i]);
    }
}

void find_ans()
{
    for (int i = 0; i < m; ++i) {

        int len = strs[i].size();

        for (int j = 1; j <= len / 2; ++j) {
            
            if (strs[i].substr(0, j) == strs[i].substr(len - j, j)) {
                if (S.count(strs[i].substr(j, len - 2 * j))) ans ++;
            }
        }
    }
}