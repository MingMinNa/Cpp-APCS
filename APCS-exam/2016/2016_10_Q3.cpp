#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c296 (3. 定時K彈)

int n, m, k;

void read_input();
int find_ans();

int main() 
{
    read_input();
    printf("%d", find_ans());
}

void read_input() 
{
    scanf("%d %d %d", &n, &m, &k);
}

int find_ans() 
{
    int idx = 0;

    for (int i = n - k + 1; i <= n; ++i) {
        idx = (idx + m) % i;
    }
    
    return idx + 1;
}