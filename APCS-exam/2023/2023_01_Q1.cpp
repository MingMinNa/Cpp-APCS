#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=j605 (1. 程式考試)

int K, ans_total = 0, ans_t = 0;
vector<pair<int, int>> vec;

void read_input();
void find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << ans_total << " " << ans_t;
}

void read_input() 
{
    cin >> K;
    vec.resize(K);

    for (int i = 0; i < K; ++i) {
        cin >> vec[i].first >> vec[i].second;
    }
}

void find_ans() 
{    
    int maxi = INT_MIN, t = K, severe_t = 0;

    for (int i = 0; i < K; ++i) {

        if (vec[i].second == -1) {
            severe_t ++;
        }
        else if (maxi < vec[i].second) {
            ans_t = vec[i].first;
            maxi = vec[i].second;
        }
    }
    
    ans_total = max(0, maxi - t - 2 * severe_t);
}