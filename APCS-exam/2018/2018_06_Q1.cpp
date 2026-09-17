#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=e283 (1. 特殊編碼)

map<vector<int>, char> mapping = {
    {{0, 1, 0, 1}, 'A'},
    {{0, 1, 1, 1}, 'B'},
    {{0, 0, 1, 0}, 'C'},
    {{1, 1, 0, 1}, 'D'},
    {{1, 0, 0, 0}, 'E'},
    {{1, 1, 0, 0}, 'F'}
};

int n;
vector<int> vec(4);

void read_input();


int main() 
{
    while (scanf("%d", &n) != EOF) {
        read_input();
    }
}

void read_input() 
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j)
            scanf("%d", &vec[j]);
        printf("%c", mapping[vec]);
    }
    printf("\n");
}