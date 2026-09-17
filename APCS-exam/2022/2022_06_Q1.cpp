#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=i399 (1. 數字遊戲)

int A[3];

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &A[i]);
    }
}

void find_ans() 
{
    int m = 0;
    int digit_count[10] = {0};
    
    for (int i = 0; i < 3; ++i) {
        digit_count[A[i]] ++;
        m = max(m, digit_count[A[i]]);
    }

    printf("%d ", m);
    for (int i = 9; i >= 0; --i) {
        if (digit_count[i]) printf("%d ", i);
    }
}