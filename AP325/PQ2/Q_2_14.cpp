#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d023

typedef long long LL;

LL panel_count, pour_pos, water_volume;
vector<LL> panel_height, water_level;
priority_queue<pair<LL, int>> pq;

void read_input();
void distribute_water(int left_bound, int right_bound, int pour_pos, LL water);


int main() 
{
    read_input();
    distribute_water(0, panel_count - 1, pour_pos, water_volume);

    for (auto &depth : water_level) {
        printf("%lld ", depth);
    }
}

void read_input() 
{
    scanf("%lld %lld %lld", &panel_count, &pour_pos, &water_volume);

    panel_height = vector<LL>(panel_count);
    water_level = vector<LL>(panel_count - 1);

    for (int i = 0; i < panel_count; ++i) {
        scanf("%lld", &panel_height[i]);
        pq.push({panel_height[i], i});
    }
}

void distribute_water(int left_bound, int right_bound, int pour_pos, LL water) 
{
    if (left_bound + 1 == right_bound) {
        water_level[pour_pos] = water;
        return;
    }

    int tallest_idx = -1;
    LL tallest_height = LLONG_MIN;

    while (!pq.empty()) {

        int idx = pq.top().second;
        pq.pop();

        if (left_bound < idx && idx < right_bound) {
            tallest_idx = idx;
            tallest_height = panel_height[idx];
            break;
        }
    }

    if ((right_bound - left_bound) * tallest_height <= water) {
        for (int i = left_bound; i < right_bound; ++i) {
            water_level[i] = water / (right_bound - left_bound);
        }
        return;
    }

    auto calc_volume = [&](int l, int r) {
        return min(panel_height[l], panel_height[r]) * (r - l);
    };

    bool right_side = false;
    int sub_left, sub_right;

    if (pour_pos >= tallest_idx) {
        sub_left = tallest_idx;
        sub_right = right_bound;
        right_side = true;
    }
    else {
        sub_left = left_bound;
        sub_right = tallest_idx;
        right_side = false;
    }

    LL basin_capacity = calc_volume(sub_left, sub_right);

    if (basin_capacity >= water) {
        distribute_water(sub_left, sub_right, pour_pos, water);
        return;
    }

    for (int i = sub_left; i < sub_right; ++i) {
        water_level[i] = tallest_height;
    }

    water -= tallest_height * (sub_right - sub_left);
    if (right_side) distribute_water(left_bound, tallest_idx, tallest_idx - 1, water);
    else            distribute_water(tallest_idx, right_bound, tallest_idx, water);
}