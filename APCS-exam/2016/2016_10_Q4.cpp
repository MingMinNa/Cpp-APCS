#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c297 (4. 棒球遊戲)

int b;
bool base[3] = {false, false, false};
vector<queue<string>> play(9);

void read_input();
int find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    cout << find_ans();
}

void read_input() 
{
    int n;
    string p;
    
    for (int i = 0; i < 9; ++i) {

        cin >> n;

        for (int j = 0; j < n; ++j) {
            cin >> p;
            play[i].push(p);
        }
    }

    cin >> b;
}

int find_ans() 
{
    int idx = 0;
    int acc_out = 0, curr_out = 0, score = 0;

    while (acc_out < b) {
        
        string res = play[idx].front(); play[idx].pop();

        if (res == "1B") {
            score += base[2];
            base[2] = base[1];
            base[1] = base[0];
            base[0] = true;
        }
        else if (res == "2B") {
            score += base[2] + base[1];
            base[2] = base[0];
            base[1] = true;
            base[0] = false;
        }
        else if (res == "3B") {
            score += base[2] + base[1] + base[0];
            base[2] = true;
            base[1] = false;
            base[0] = false;
        }
        else if (res == "HR") {
            score += base[2] + base[1] + base[0] + 1;
            base[2] = false;
            base[1] = false;
            base[0] = false;
        }
        else {
            curr_out ++;
            acc_out ++;
        }

        if (curr_out == 3) {
            curr_out = 0;
            base[2] = false;
            base[1] = false;
            base[0] = false;
        }

        idx = (idx + 1) % 9;
    }

    return score;
}