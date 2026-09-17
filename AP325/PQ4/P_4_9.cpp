#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d049

int N, K, ans = 0;
vector<int> vec;

void read_input();
void find_ans();
bool check(int diameter);


int main()
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input()
{
    scanf("%d %d", &N, &K);
    vec.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &vec[i]);
    }
}

void find_ans()
{
    sort(vec.begin(), vec.end());

    int min_d = 1;
    int max_d = vec[N - 1] - vec[0];

    for (int jump = (max_d - min_d) >> 1; jump >= 1; jump >>= 1) {
        while (!check(ans + jump)) {
            ans += jump;
        }
    }

    ans ++;
}

bool check(int diameter)
{
    int curr = -1, k = K;

    for (int i = 0; i < N; ++i) {
        if (curr < vec[i]) {
            curr = vec[i] + diameter;
            k --;
        }
    }

    return k >= 0;
}