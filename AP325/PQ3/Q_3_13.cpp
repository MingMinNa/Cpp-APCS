#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d037

struct Point {
    int x, y;
};

int N, L, ans = 0;
vector<Point> vec;

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
    scanf("%d %d", &N, &L);
    vec.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &vec[i].x);
    }
    
    for (int i = 0; i < N; ++i) {
        scanf("%d", &vec[i].y);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Point &p1, const Point &p2) {
        return p1.x < p2.x || (p1.x == p2.x &&  p1.y < p2.y);
    });

    int left = 0;
    deque<int> min_y_dq, max_y_dq;

    for (int i = 0; i < N; ++i) {

        while (!min_y_dq.empty() && min_y_dq.back() > vec[i].y) min_y_dq.pop_back();
        while (!max_y_dq.empty() && max_y_dq.back() < vec[i].y) max_y_dq.pop_back();

        while (left < i && vec[i].x - vec[left].x > L) {
            if (!min_y_dq.empty() && min_y_dq.front() == vec[left].y) min_y_dq.pop_front();
            if (!max_y_dq.empty() && max_y_dq.front() == vec[left].y) max_y_dq.pop_front();
            left ++;
        }

        min_y_dq.push_back(vec[i].y);
        max_y_dq.push_back(vec[i].y);

        ans = max(ans, max_y_dq.front() - min_y_dq.front());
    }
}