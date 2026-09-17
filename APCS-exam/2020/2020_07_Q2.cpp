#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f580 (2. 骰子)

struct Dice {
    int front;
    int top;
    int right;

    Dice(int f = 4, int r = 2, int t = 1) 
    {
        front = f;
        right = r;
        top = t;
    }
};

int n, m;
vector<Dice> dices;
vector<pair<int,int>> ops;

void read_input();
void find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    
    for (int i = 1; i <= n; ++i) {
        cout << dices[i].top << " ";
    }
}

void read_input() 
{
    cin >> n >> m;
    dices.resize(n + 1);
    ops.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> ops[i].first >> ops[i].second;
    }
}

void find_ans() 
{
    for (int i = 0; i < m; ++i) {
        int index = ops[i].first;
        int op = ops[i].second;

        if (op == -1) {
            dices[index] = Dice(
                dices[index].top, 
                dices[index].right, 
                7 - dices[index].front
            );
        }
        else if (op == -2) {
            dices[index] = Dice(
                dices[index].front, 
                dices[index].top,
                7 - dices[index].right
            );
        }
        else {
            swap(dices[index], dices[op]);
        }
    }
}