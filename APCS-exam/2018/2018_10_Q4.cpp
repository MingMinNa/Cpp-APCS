#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d075 (4. 置物櫃出租)

int n, M, S;
vector<int> fs;

void read_input();
int find_ans();


int main() 
{
    read_input();
    printf("%d", find_ans());
}

void read_input() 
{
    scanf("%d %d %d", &n, &M, &S);
    fs.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &fs[i]);
    }
}

int find_ans() 
{
    int in_use = 0;

    for (int i = 0; i < n; ++i) {
        in_use += fs[i];
    }

    if (S <= M - in_use) {
        return 0;
    }

    vector<vector<int>> table(n + 1, vector<int>(M - S + 1));

    for (int i = 1; i <= n; ++i) {

        int j = 0;

        for (; j < min(fs[i - 1], M - S + 1); ++j) {
            table[i][j] = table[i - 1][j];
        }
        
        for (; j <= M - S; ++j) {
            table[i][j] = max(
                table[i - 1][j],
                table[i - 1][j - fs[i - 1]] + fs[i - 1]
            );
        }
    }

    return in_use - table[n][M - S];
}