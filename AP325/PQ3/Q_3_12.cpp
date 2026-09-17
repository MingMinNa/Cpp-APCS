#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d036

int n, m;
vector<int> vec;

void read_input();
int recursive(int start, int end);


int main()
{
    read_input();
    printf("%d", recursive(0, n));
}

void read_input()
{
    scanf("%d %d", &m, &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

int recursive(int start, int end)
{
    if (end - start < m) return 0;
    
    int left_ret  = recursive(start, (start + end) >> 1);
    int right_ret = recursive((start + end) >> 1, end);
    int ret = 0;

    int right = max(start + m - 1, (start + end) >> 1), left = right - m + 1;
    int curr_c = 0;

    unordered_map<int, int> color_count;
    
    for (int i = left; i <= right; ++i) {
        color_count[vec[i]] ++;
        if (color_count[vec[i]] == 1) curr_c ++;
    }

    if (curr_c == m) ret ++;

    for (++ right; left < ((start + end) >> 1) && right < end; ++ left, ++ right) {

        color_count[vec[left]] --;
        if (color_count[vec[left]] == 0) curr_c --;

        color_count[vec[right]] ++;
        if (color_count[vec[right]] == 1) curr_c ++;

        if (curr_c == m) {
            ret ++;
        }
    }

    return left_ret + right_ret + ret;
}