#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c290 (1. 秘密差)

string X;

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
    cin >> X;
}

int find_ans() 
{    
    int sum[2] = {0};

    for (int i = 0, size = X.size(); i < size; ++i) {
        sum[i % 2] += X[i] - '0';
    }
    
    return abs(sum[0] - sum[1]);
}