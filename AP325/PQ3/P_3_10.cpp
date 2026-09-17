#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d034

int n, c = 0, ans = INT_MAX;
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
    scanf("%d", &n);
    vec.resize(n);

    unordered_set<int> color_set;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
        color_set.insert(vec[i]);
    }

    c = color_set.size();
}

void find_ans()
{
    int curr_c = 0, left = 0;
    unordered_map<int, int> color_count;

    for (int i = 0; i < n; ++i) {

        color_count[vec[i]] ++;

        if (color_count[vec[i]] == 1) 
            curr_c ++;

        while (color_count[vec[left]] > 1) {
            color_count[vec[left]] --;
            left ++;
        }
        
        if (curr_c == c) {
            ans = min(ans, i - left + 1);
        }
    }
}