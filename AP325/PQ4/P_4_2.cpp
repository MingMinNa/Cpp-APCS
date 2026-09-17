#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d043

int n, ans = 0;
vector<int> enemy;
vector<int> teammate;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d", &n);
    enemy.resize(n);
    teammate.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &enemy[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &teammate[i]);
    }
}

void find_ans()
{
    sort(enemy.begin(), enemy.end());
    sort(teammate.begin(), teammate.end());

    for (int i = 0, j = 0; i < n && j < n; ++i) {
        if (teammate[i] > enemy[j]) {
            ans ++;
            j ++;
        }
    }
}