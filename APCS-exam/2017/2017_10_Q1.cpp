#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c461 (1. 邏輯運算子)

int a, b, c;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{
    cin >> a >> b >> c;
}

void find_ans() 
{
    bool possible = false;
    bool bool_a = a, bool_b = b, bool_c = c;

    if ((bool_a && bool_b) == bool_c) {
        cout << "AND\n";
        possible = true;
    }

    if ((bool_a || bool_b) == bool_c) {
        cout << "OR\n";
        possible = true;
    }

    if ((bool_a ^ bool_b) == bool_c) {
        cout << "XOR\n";
        possible = true;
    }

    if (!possible) {
        cout << "IMPOSSIBLE";
    }
}