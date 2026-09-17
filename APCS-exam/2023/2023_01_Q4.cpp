#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=j608 (4. 機器出租)

int n, k, ans = 0;
vector<pair<int, int>> activity;

void read_input();
void find_ans();


int main() 
{    
    read_input();
    find_ans();
    printf("%d\n", ans);
}

void read_input()
{
    scanf("%d %d", &n, &k);
    activity.resize(n);

    for (int i = 0; i < n; ++i) scanf("%d", &activity[i].second);
    for (int i = 0; i < n; ++i) scanf("%d", &activity[i].first);
}

void find_ans()
{
    sort(activity.begin(), activity.end());
    vector<int> end(k, -1);

    for (int i = 0; i < n; ++i) {

        int best = -1;
        
        for (int j = 0; j < k; ++j) {
            if (end[j] < activity[i].second && (best == -1 || end[j] > end[best])) {
                best = j;
            }
        }

        if (best != -1) {
            ans ++;
            end[best] = activity[i].first;
        }
    }

}