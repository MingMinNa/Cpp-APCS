#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d055

struct Point {
    int x, y;
};

int n, ans = 0;
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
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].x);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i].y);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end(), [](const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    stack<Point> stk;

    for (int i = 0; i < n; ++i) {

        while (!stk.empty() && stk.top().y <= vec[i].y) {
            stk.pop();
        }

        stk.push(vec[i]);
    }
    
    ans = stk.size();
}