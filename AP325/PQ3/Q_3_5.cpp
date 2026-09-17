#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d029

struct Person {
    int h;
    int p;
};

typedef long long LL;

int n;
LL ans = 0;
vector<Person> vec;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n + 1);
    vec[0] = {INT_MAX, INT_MAX};

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &vec[i].h);
    }
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &vec[i].p);
    }
}

void find_ans()
{
    vector<pair<int, int>> stk;
    stk.push_back({INT_MAX, 0});

    auto binary_search = [&] (pair<LL, int> target) {
        int curr = 0;
        for (int jump = stk.size() >> 1; jump >= 1; jump >>= 1) {
            while (curr + jump < (int)stk.size() && stk[curr + jump].first > target.first) {
                curr += jump;
            }
        }
        return curr;
    };

    for (int i = 1; i <= n; ++i) {
        
        while (vec[i].h >= stk[stk.size() - 1].first) stk.pop_back();

        int idx = binary_search({vec[i].h + vec[i].p, 0});
        ans += (i - stk[idx].second - 1);
        stk.push_back({vec[i].h, i});
    }
}