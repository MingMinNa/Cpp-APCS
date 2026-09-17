#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=h026 (1. 猜拳)

int F, N;
vector<int> y;

int defeat[6] = {
    5, -1, 0, -1, -1, 2
};

void read_input();
void find_ans();
int beat(int x, int y);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
}

void read_input() 
{
    cin >> F;
    cin >> N;
    y.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> y[i];
    }
}

void find_ans() 
{
    int res = 0;
    int round = 1;
    int b = F, s;

    for (int i = 0; i < N; ++i, ++round) {
        
        s = y[i];
        res = beat(b, s);

        printf("%d ", b);

        if (res != 0) break;

        if (res == 0 && i > 0 && y[i - 1] == s) {
            b = defeat[s];
        }
        else if (res == 0) {
            b = s;
        }
    }

    if      (res == 0)   printf(": Drew at round %d", N);
    else if (res == -1)  printf(": Lost at round %d", round);
    else                 printf(": Won at round %d", round);
}

int beat(int x, int y) 
{    
    if (x == y) return 0;

    int val[3] = {0, 2, 5};

    for (int i = 0; i < 3; ++i) {
        if (x == val[i] && y == val[(i + 1) % 3])
            return 1;
    }
    
    return -1;
}