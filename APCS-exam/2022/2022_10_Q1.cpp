#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=i428 (1. 巴士站牌)

int n, maxi = INT_MIN, mini = INT_MAX;
vector<pair<int, int>> vec;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
    printf("%d %d", maxi, mini);
}

void read_input() 
{
    scanf("%d", &n);
    vec.resize(n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &vec[i].first, &vec[i].second);
    }
}

void find_ans() 
{
    for (int i = 0; i < n - 1; ++i) {

        int dist = \
            abs(vec[i].first - vec[i + 1].first) + 
            abs(vec[i].second - vec[i + 1].second);

        maxi = max(maxi, dist);
        mini = min(mini, dist); 
    }
}