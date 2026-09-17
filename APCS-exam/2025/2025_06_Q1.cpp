#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=q836 (1. 小心陷阱)

int k;
int x_1, y_1;
int x_2, y_2;

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
    cin >> k;
    cin >> x_1 >> y_1;
    cin >> x_2 >> y_2;
}

int find_ans() 
{
    int pos = 0, health = k;

    while (health > 0) {

        pos += health;

        if (pos % x_1 == 0) health -= y_1;
        if (pos % x_2 == 0) health -= y_2;
    }

    return pos;
}