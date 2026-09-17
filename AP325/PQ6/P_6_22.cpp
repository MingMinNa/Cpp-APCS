#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d083

struct Member {
    int p, c, m;
};

int n;
vector<Member> vec;

void read_input();
int find_ans();


int main()
{
    read_input();
    printf("%d", find_ans());
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].p);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].c);
    }
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].m);
    }
}

int find_ans()
{
    sort(vec.begin(), vec.end(), [](const Member &a, const Member &b) {
        return a.c > b.c || (a.c == b.c && a.m < b.m);
    });

    int ans = 0;
    map<int, int> M;    // (m, p)
    M[-1] = 0;

    for (int i = 0; i < n; ++i) {

        auto it = M.upper_bound(vec[i].m); 
        it --;
        
        int w = it->second + vec[i].p;
        it = M.insert(it, {vec[i].m, w});
        ans = max(ans, w);
        
        // if vec[i].m in M, then M.insert will not change M[vec[i].m]
        if (it->second < w) {
            it->second = w;
        }

        it ++;
        while (it != M.end() && it->second <= w) {
            it = M.erase(it);
        }
    }

    return ans;
}