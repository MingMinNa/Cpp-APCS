#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d030

typedef long long LL;

struct Tree {
    int h, pos;
};

int N, L, ans = 0, ans_h = 0;
vector<Tree> vec;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%d\n%d", ans, ans_h);
}

void read_input()
{
    scanf("%d %d", &N, &L);
    vec.resize(N + 2);

    vec[0]     = {.h = INT_MAX, .pos = 0};
    vec[N + 1] = {.h = INT_MAX, .pos = L};
    
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &vec[i].pos);
    }

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &vec[i].h);
    }
}

void find_ans()
{
    stack<Tree> stk;
    stk.push(vec[0]);

    for (int i = 1; i <= N; ++i) {
        Tree curr = vec[i];

        if (curr.pos - curr.h >= stk.top().pos || 
            curr.pos + curr.h <= vec[i + 1].pos
        ) {
            ans ++;
            ans_h = max(curr.h, ans_h);
            
            while (!stk.empty() && stk.top().pos + stk.top().h <= vec[i + 1].pos) {
                ans ++;
                ans_h = max(stk.top().h, ans_h);
                stk.pop();
            }

            continue;
        }
        
        stk.push(vec[i]);
    }
}