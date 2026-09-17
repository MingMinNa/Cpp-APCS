#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d118

struct Segment {
    int L, R, W;
};

int n, ans = 0;
vector<Segment> vec;

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
    vec.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &vec[i].L, &vec[i].R, &vec[i].W);
    }
}

void find_ans()
{
    vec[0].R = -1;
    sort(vec.begin(), vec.end(), [](const Segment &a, const Segment &b) {
        return a.R < b.R;
    });

    vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
    
        int j = 0;
    
        for (int jump = i >> 1; jump >= 1; jump >>= 1) {
            while (j + jump < i && vec[j + jump].R < vec[i].L) {
                j += jump;
            }
        }

        dp[i] = max(dp[i - 1], dp[j] + vec[i].W);
    }
    
    ans = dp[n];
}