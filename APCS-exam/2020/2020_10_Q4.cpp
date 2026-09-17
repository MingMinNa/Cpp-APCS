#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f315 (4. 低地距離)

typedef long long LL;

struct Fenwick {
    int n;
    vector<int> data;

    int lowbit(int i) 
    {
        return i & (-i);
    }

    void init(int n) 
    {
        this->n = n;
        data.resize(n + 1);
    }

    void update(int idx, int val) 
    {
        for (; idx <= n; idx += lowbit(idx)) {
            data[idx] += val;
        }
    }
    
    int query(int idx) 
    {
        int res = 0;

        for (; idx > 0; idx -= lowbit(idx)) {
            res += data[idx];
        }
        
        return res;
    }
};

int n;
LL ans = 0;
Fenwick fenwick;
vector<pair<int, int>> record;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{
    scanf("%d", &n);
    record.resize(n + 1, {-1, -1});
    fenwick.init(2 * n);
    
    int val;

    for (int i = 0; i < 2 * n; ++i) {

        scanf("%d", &val);
        
        if (record[val].first == -1) record[val].first = i;
        else                        record[val].second = i;
    }
}

void find_ans() 
{
    LL ans = 0;

    for (int val = 1; val <= n; ++val) {

        // Fenwick is 1-based
        int left = record[val].first + 1; 
        int right = record[val].second + 1;

        ans += fenwick.query(right) - fenwick.query(left);

        fenwick.update(left, 1);
        fenwick.update(right, 1);
    }
    
    printf("%lld", ans);
}