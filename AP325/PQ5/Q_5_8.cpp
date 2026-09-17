#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d036

typedef long long LL;

int m, n;
LL ans = 0;
vector<int> vec;

void read_input();
void recursive(int start, int end);


int main()
{
    read_input();
    recursive(0, n);
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &m, &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

void recursive(int start, int end)
{
    if (end - start < m) return;

    int mid = (start + end) >> 1;
    recursive(start, mid);
    recursive(mid, end);

    int right_start = max(start + m - 1, mid), curr_c = 0;
    unordered_map<int, int> color_c;

    for (int i = right_start - m + 1; i <= right_start; ++i) {
        
        color_c[vec[i]] ++;
        
        if (color_c[vec[i]] == 1)
            curr_c ++;
    }

    if (curr_c == m) ans ++;

    int i = right_start - m + 1, j = right_start;
    
    for (++i, ++j; j < end && i < mid; ++i, ++j) {

        color_c[vec[i - 1]] --;
        if (color_c[vec[i - 1]] == 0) curr_c --;

        color_c[vec[j]] ++;
        if (color_c[vec[j]] == 1) curr_c ++;

        if (curr_c == m) ans ++;
    }
}