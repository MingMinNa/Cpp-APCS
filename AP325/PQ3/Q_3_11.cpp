#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d035

int n, ans = 0;
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

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

void find_ans()
{
    int left = 0;
    vector<int> color_index(n);
    
    for (int i = 0; i < n; ++i) {
        
        color_index[vec[i]] ++;

        while (color_index[vec[i]] > 1) {
            color_index[vec[left]] --;
            left ++;
        }

        ans = max(ans, i - left + 1);
    }
}