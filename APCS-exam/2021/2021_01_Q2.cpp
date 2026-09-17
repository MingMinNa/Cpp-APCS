#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f606 (2. 流量)

typedef long long LL;

int n, m, k;
LL ans_cost = LLONG_MAX;
vector<vector<LL>> Q, pos;

void read_input();
void find_ans();
LL calc(vector<vector<LL>> &temp_Q, int server, int city, bool same);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << ans_cost;
}

void read_input() 
{
    cin >> n >> m >> k;
    Q.resize(n, vector<LL>(m));
    pos.resize(k, vector<LL>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> Q[i][j];
        }
    }
    
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> pos[i][j];
        }
    }   
}

void find_ans() 
{    
    for (int l = 0; l < k; ++l) {

        LL cost = 0;
        unordered_map<int, int> record;
        vector<vector<LL>> temp_Q(Q);

        // pos[l][i] is the city in which the i-th server is located.
        for (int i = 0; i < n; ++i) {

            if (record.count(pos[l][i])) {

                int idx = record[pos[l][i]];
                
                for (int j = 0; j < m; ++j) {
                    temp_Q[idx][j] += Q[i][j];
                }
                
                pos[l][i] = -1;
            }
            else {
                record[pos[l][i]] = i;
            }            
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                // Information about this server has been stored on other servers.
                if (pos[l][i] == -1) continue;
                cost += calc(temp_Q, i, j, pos[l][i] == j);
            }
        }

        ans_cost = min(ans_cost, cost);
    }
}

LL calc(vector<vector<LL>> &temp_Q, int server, int city, bool same) 
{
    if (same)                         return temp_Q[server][city];
    if (temp_Q[server][city] <= 1000) return 3 * temp_Q[server][city];
    return 3 * 1000 + 2 * (temp_Q[server][city] - 1000);
}