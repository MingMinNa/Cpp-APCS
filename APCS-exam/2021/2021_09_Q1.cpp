#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=g275 (1. 七言對聯)

int n, couplets[2][8];

void read_input();
string find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        read_input();
        cout << find_ans() << endl;
    }
}

void read_input() 
{
    for (int i = 0; i < 2; ++i) {
        for (int j = 1; j <= 7; ++j) {
            scanf("%d", &couplets[i][j]);
        }
    }    
}

string find_ans() 
{
    auto check_A = [&](int i) {
        return \
            couplets[i][2] != couplets[i][4] && 
            couplets[i][2] == couplets[i][6];
    };

    auto check_B = [&]() {
        return \
            couplets[0][7] == 1 && 
            couplets[1][7] == 0;
    };

    auto check_C = [&]() {
        for (int i = 2; i <= 7; i += 2) {
            if (couplets[0][i] == couplets[1][i]) return false;    
        }
        return true;
    };

    string res = "";

    if (!check_A(0) || !check_A(1))  res += "A";
    if (!check_B())                  res += "B";
    if (!check_C())                  res += "C";
    
    return (res == "") ? "None" : res;
}