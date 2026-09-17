#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=g598 (4. 真假子圖)

int n, m, p, k, color[20005];
vector<int> now[20005];
vector<pair<int, int>> e, v[10005];

void read_input();
void find_ans();
bool dfs(int x, int pre);
bool check(int x);
 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read_input();
    find_ans();
}

void read_input()
{
    cin >> n >> m;

    for (int i = 0, x, y; i < m; i++) {

        cin >> x >> y;
        
        x ++, y ++;
        e.push_back({x, y});
    }

    cin >> p >> k;

    for (int i = 1, x, y; i <= p; i++) {
        for (int j = 0; j < k; j++) {
            
            cin >> x >> y;
            
            x ++, y ++;
            v[i].push_back({x, y});
        }
    }
}

void find_ans() 
{
    int l = 0, r = p;

    for (int i = 0; i < 3; i++) {

        while (r - l > 1) {

            int mid = (l + r) / 2;
            
            if (check(mid)) l = mid;
            else            r = mid;
        }

        cout << r << "\n";
        v[r].clear();

        l = r;
        r = p;

        if (check(p)) break;
    }
}

bool dfs(int x, int pre)
{
    for (int i : now[x]) {

        if (i == pre) continue;
        
        if (!color[i]) {
            color[i] = 3 - color[x];
            if (!dfs(i, x)) return false;
        }
        else if (color[i] == color[x]) {
            return false;
        }
    }

    return true;
}

bool check(int x)
{
    for (int i = 1; i <= n; i++) {
        color[i] = 0;
        now[i].clear();
    }

    for (auto i : e) {
        now[i.first].push_back(i.second);
        now[i.second].push_back(i.first);
    }

    for (int i = 1; i <= x; i++) {
        for (auto j : v[i]){
            now[j.first].push_back(j.second);
            now[j.second].push_back(j.first);
        }
    }

    for (int i = 1; i <= n; i++) {

        if (!color[i]) {
            color[i] = 1;
            if (!dfs(i, 0)) return false;
        }
    }
    
    return true;
}