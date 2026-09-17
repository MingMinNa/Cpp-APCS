#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=e286 (1. 籃球比賽)

int host[2][4];
int guest[2][4];

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) scanf("%d", &host[i][j]);
        for (int j = 0; j < 4; ++j) scanf("%d", &guest[i][j]);
    }
}

void find_ans() 
{
    int win = 0;

    for (int i = 0; i < 2; ++i) {

        for (int j = 1; j < 4; ++j) {
            host[i][j] += host[i][j - 1];
            guest[i][j] += guest[i][j - 1];
        }

        if (host[i][3] > guest[i][3]) {
            win ++;
        }
        else {
            win --;
        }

        printf("%d:%d\n", host[i][3], guest[i][3]);
    }

    if      (win == 0) printf("Tie");
    else if (win == 2) printf("Win");
    else               printf("Lose");
}