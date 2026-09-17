#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=e313 (1. 最少相異字母)

int n;
vector<pair<int, string>> strs;

void read_input();
string find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    cout << find_ans();
}

void read_input() 
{
    cin >> n;
    strs.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> strs[i].second;
    }
}

string find_ans() 
{
    vector<char> alpha_count(26);

    for (int i = 0; i < n; ++i) {

        std::fill(alpha_count.begin(), alpha_count.end(), 0);
        
        for (const auto &c : strs[i].second) {
            
            if (alpha_count[c - 'A'] == 0) {
                strs[i].first ++;
                alpha_count[c - 'A'] = 1;
            }
        }
    }

    sort(strs.begin(), strs.end());
    return strs[0].second;
}