#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=m370 (1. 機械鼠)

int x, n, max_count = 0, last_pos = 0;
vector<int> vec;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
    printf("%d %d", max_count, last_pos);
}

void read_input() 
{
    scanf("%d %d", &x, &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

void find_ans() 
{
    sort(vec.begin(), vec.end());

    int size = vec.size();
    int left = 0, right = size - 1;

    for (; left < size && vec[left] <= x; left ++);
    for (; right >= 0 && vec[right] >= x; right --);
    
    if (left > (size - 1) - right) {
        max_count = left;
        last_pos = vec[0];
    }
    else {
        max_count = (size - 1) - right;
        last_pos = vec[size - 1];
    }
}