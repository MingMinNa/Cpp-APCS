#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=i401 (3. 雷射測試)

int r = 0, c = 0, dir = 0, n, ans; 
map<int, vector<pair<int, int>>> table_r, table_c;
// dir = 0: right, 1: left, 2: top, 3: down

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

    int r, c, d;

    for (int i = 0; i < n; ++i) {

        scanf("%d %d %d", &c, &r, &d);

        table_r[r].push_back({c, d});
        table_c[c].push_back({r, d});
    }

    for (auto & e : table_r) sort(e.second.begin(), e.second.end());
    for (auto & e : table_c) sort(e.second.begin(), e.second.end());
}

void find_ans() 
{
    int cnt = 0;
    vector<pair<int, int>>::iterator it;

    while (1) {
        if (dir == 0) {

            if (table_r[r].size() == 0) break;

            it = upper_bound(table_r[r].begin(), table_r[r].end(), make_pair(c, INT_MAX));

            if (it == table_r[r].end()) break;

            if (it->second == 0) dir = 2;
            else                 dir = 3;

            c = it->first;
        }
        else if (dir == 1) {

            if (table_r[r].size() == 0) break;

            it = lower_bound(table_r[r].begin(), table_r[r].end(), make_pair(c, -1));

            if (it == table_r[r].begin()) break;

            --it;

            if (it->second == 0) dir = 3;
            else                 dir = 2;

            c = it->first;
        }
        else if (dir == 2) {

            if (table_c[c].size() == 0) break;

            it = upper_bound(table_c[c].begin(), table_c[c].end(), make_pair(r, INT_MAX));

            if (it == table_c[c].end()) break;

            if (it->second == 0) dir = 0;
            else                 dir = 1;

            r = it->first;
        }
        else if (dir == 3) {

            if (table_c[c].size() == 0) break;

            it = lower_bound(table_c[c].begin(), table_c[c].end(), make_pair(r, -1));

            if (it == table_c[c].begin()) break;

            --it;

            if (it->second == 0) dir = 1;
            else                 dir = 0;

            r = it->first;
        }

        cnt ++;
    }
    
    ans = cnt;
}