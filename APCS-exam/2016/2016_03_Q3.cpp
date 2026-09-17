#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=b966 (3. 線段覆蓋長度)

int n;
vector<pair<int, int>> segments;

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
    segments.resize(n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", 
            &segments[i].first, 
            &segments[i].second
        );
    }
}

int find_ans() 
{    
    sort(segments.begin(), segments.end());

    int ans = 0;
    int left = 0, right = 0;
    
    for (auto &p : segments) {
        
        if (p.first >= right) {
            ans += right - left;
            left = p.first, right = p.second;
        }
        else if (p.second > right) {
            right = p.second;
        }
    }
    
    ans += right - left;
    return ans;
}