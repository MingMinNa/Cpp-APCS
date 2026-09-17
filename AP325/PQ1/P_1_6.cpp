#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d020 (TLE)

int n, K, ans = INT_MIN;
vector<int> arr;

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
    scanf("%d %d", &n, &K);
    arr.resize(n + 1);

    // Prefix Sum
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
}

void find_ans()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {

            int interval_sum = arr[i] - arr[j];
            if (interval_sum <= K && interval_sum > ans) {
                ans = interval_sum;
            }
        }
    }
}