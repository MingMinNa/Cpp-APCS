#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=h084 (4. 牆上海報)

int n, k, ans = 1, max_h;
vector<int> h_vec, w_vec;

void read_input();
void find_ans();
bool check(int h);


int main()
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d %d", &n, &k);
    h_vec.resize(n);
    w_vec.resize(k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &h_vec[i]);
        max_h = max(max_h, h_vec[i]);
    }

    for (int i = 0; i < k; ++i) {
        scanf("%d", &w_vec[i]);
    }
}

void find_ans()
{
    int left = 1, right = max_h;

    for (int jump = (right - left) >> 1; jump >= 1; jump >>= 1) {
        while (left + jump <= right && check(left + jump)) {
            left += jump;
        }
    }

    ans = left;
}

bool check(int h)
{
    int i, j, l;

    for (i = 0, j = 0; i < k && j < n;) {

        l = w_vec[i];

        if (h_vec[j] < h) {
            ++j;
            continue;
        }

        while (l > 0 && h_vec[j] >= h) {
            --l;
            ++j;
        }
        
        if (l == 0) {
            ++i;
        }
    }

    if (i == k) return true;
    return false;
}