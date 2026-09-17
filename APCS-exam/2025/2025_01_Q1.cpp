#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=q181 (1. 等紅綠燈)

int a, b, n, ans = 0;
vector<int> t;

void read_input();
void find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << ans;
}

void read_input() 
{
    cin >> a >> b >> n;
    t.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
}

void find_ans() 
{
    int curr_t = 0;

    for (int i = 0; i < n; ++i) {

        curr_t += t[i];
        curr_t %= (a + b);

        if (curr_t >= a) {
            ans += (a + b) - curr_t;
        }
        
        curr_t = 0;
    }
}