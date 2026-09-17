#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d089

int n, start, ans = INT_MAX;
vector<vector<int>> dist;
unordered_map<uint64_t, int> dp;

void read_input();
void find_ans();
int TSP(int start, int end, int intermediates);
inline uint64_t encode(int s, int e, int mask);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << ans << endl;
}

void read_input() 
{
    cin >> n >> start;
    dist.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
}

void find_ans() 
{
    int intermediates = ((1 << n) - 1) ^ (1 << start);

    for (int i = 0; i < n; i++) {
        
        if (i == start) continue;

        int mask = intermediates ^ (1 << i);
        ans = min(ans, TSP(i, start, mask) + dist[start][i]);
    }
}

int TSP(int start, int end, int intermediates) 
{
    uint64_t key = encode(start, end, intermediates);

    if (intermediates == 0 || start == end)
        return dist[start][end];

    if (dp.count(key))
        return dp[key];

    int n = dist.size();
    int best = INT_MAX;

    for (int v = 0; v < n; v++) {
        if (intermediates & (1 << v)) {
            int val = TSP(v, end, intermediates ^ (1 << v)) + dist[start][v];
            best = min(best, val);
        }
    }

    dp[key] = best;
    return best;
}

// (start, end, intermediates) --> 64-bit key
inline uint64_t encode(int s, int e, int mask) 
{
    return ((uint64_t)s << 40) | ((uint64_t)e << 32) | (uint64_t)mask;
}