#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=e289 (4. 美麗的彩帶)

typedef long long LL;

int m, n; 
LL ans = 0;
vector<string> ribbon;
map<string, int> record;

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
    cin >> m >> n;
    ribbon.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> ribbon[i];
    }
}

void find_ans() 
{
    int color_count = 0, left = 0, right = 0;
    string color;

    for (; right < min(n, m); ++right) {

        color = ribbon[right];
        record[color] ++;

        if (record[color] == 1) {
            color_count ++;
        }
    }

    if (color_count == m) ans ++;

    for (; right < n; ++right, ++left) {
        
        color = ribbon[right];
        record[color] ++;

        if (record[color] == 1) {
            color_count ++;
        }

        color = ribbon[left];
        record[color] --;
        
        if (record[color] == 0) {
            color_count --;
        }

        if (color_count == m) ans ++;
    }
}