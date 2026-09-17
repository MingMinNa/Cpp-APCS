#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d033

int n, L, ans = 0;
vector<int> vec;

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
    scanf("%d %d", &n, &L);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

void find_ans()
{
    unordered_map<int, int> color;
    int left = 0, right = 0;

    for (; right - left + 1 <= L; ++right) {
        color[vec[right]] ++;
    }

    ans = max(ans, (int)color.size());

    for (; right < n; ++right, ++left) {

        color[vec[left]] --;
        color[vec[right]] ++;

        if (color[vec[left]] == 0) color.erase(vec[left]);
        ans = max(ans, (int)color.size());
    }
}