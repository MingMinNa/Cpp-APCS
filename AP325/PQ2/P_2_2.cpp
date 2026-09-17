#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d011

int n;
vector<int> nums;
map<int, int> rank_map;

void read_input();


int main() 
{
    read_input();
    for (int i = 0; i < n; ++i) {
        printf("%d ", rank_map[nums[i]]);
    }
}

void read_input() 
{
    scanf("%d", &n);
    nums.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
        rank_map[nums[i]] = 0;
    }

    int idx = 0;
    for (auto it = rank_map.begin(); it != rank_map.end(); ++it, ++idx) {
        it->second = idx;
    }
}