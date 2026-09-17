#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=o711 (1. 裝飲料)

int n, w1, w2, h1, h2, ans = 0;
vector<int> water_vec;

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
    cin >> n;
    cin >> w1 >> w2 >> h1 >> h2;
    water_vec.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> water_vec[i];
    }
}

void find_ans() 
{
    int curr_h = 0;

    for (int i = 0; i < n; ++i) {

        int water = water_vec[i];
        int next_h = curr_h;

        if (next_h < h1 && water <= (h1 - curr_h) * w1 * w1) {
            next_h += water / (w1 * w1);
            water = 0;
        }
        else if (next_h <= h1) {
            next_h = h1;
            water -= (h1 - curr_h) * w1 * w1;
        }

        if (h1 <= next_h && water > 0) {
            next_h = min(h2 + h1, next_h + water / (w2 * w2));
        }

        ans = max(ans, next_h - curr_h);
        curr_h = next_h;
    }
}