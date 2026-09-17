#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f607 (3. 切割費用)

typedef long long LL;

int n, L;
LL ans = 0;
set<int> endpoints;
vector<pair<int, int>> cut;

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
    cin >> n >> L;
    cut.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> cut[i].second >> cut[i].first;
    }
}

void find_ans() 
{    
    sort(cut.begin(), cut.end());
    
    endpoints.insert(L);
    endpoints.insert(0);

    for (int i = 0; i < n; ++i) {
        
        auto it = endpoints.lower_bound(cut[i].second);
        ans += 1ll * (*it) - *(prev(it));
        endpoints.insert(cut[i].second);
    }
}