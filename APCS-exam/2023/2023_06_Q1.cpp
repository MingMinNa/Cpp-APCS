#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=k731 (1. 路徑偵測)

int n, left_t = 0, right_t = 0, rotate_t = 0;
vector<pair<int, int>> points;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
    printf("%d %d %d", left_t, right_t, rotate_t);
}

void read_input() 
{
    scanf("%d", &n);
    points.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &points[i].second, &points[i].first);
    }
}

void find_ans() 
{
    // dir = 0; /*  up   */
    // dir = 1; /* left  */
    // dir = 2; /* down  */ 
    // dir = 3; /* right */

    int dir = 0;

    if      (points[0].first > 0)  dir = 0;
    else if (points[0].second > 0) dir = 3;

    auto is_left = [&](int i) {
        
        if (dir == 0 && points[i].second < points[i - 1].second) return true;
        if (dir == 1 && points[i].first < points[i - 1].first)   return true;
        if (dir == 2 && points[i].second > points[i - 1].second) return true;
        if (dir == 3 && points[i].first > points[i - 1].first)   return true;

        return false;
    };

    auto is_right = [&](int i) {

        if (dir == 0 && points[i].second > points[i - 1].second) return true;
        if (dir == 1 && points[i].first > points[i - 1].first)   return true;
        if (dir == 2 && points[i].second < points[i - 1].second) return true;
        if (dir == 3 && points[i].first < points[i - 1].first)   return true;

        return false;
    };

    auto is_rotate = [&](int i) {

        if (dir == 0 && points[i].first < points[i - 1].first)   return true;
        if (dir == 1 && points[i].second > points[i - 1].second) return true;
        if (dir == 2 && points[i].first > points[i - 1].first)   return true;
        if (dir == 3 && points[i].second < points[i - 1].second) return true;

        return false;
    };

    for (int i = 1; i < n; ++i) {

        if (is_left(i)) {
            left_t ++;
            dir = (dir + 1) % 4;
            continue;
        }

        if (is_right(i)) {
            right_t ++;
            dir = (dir + 3) % 4;
            continue;
        }
        
        if (is_rotate(i)) {
            rotate_t ++;
            dir = (dir + 2) % 4;
            continue;
        }
    }
}