#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d020

int n, K, ans = INT_MIN;
vector<int> arr;
set<int> prefix_set;

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
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
}

void find_ans()
{
    int prefix = 0;
    prefix_set.insert(0);

    for (int i = 0; i < n; ++i) {

        prefix += arr[i];
        
        // prefix[i] - prefix[x] <= K
        // prefix[x] >= prefix[i] - K
        auto it = prefix_set.lower_bound(prefix - K);

        if (it != prefix_set.end()) {
            ans = max(ans, prefix - *it);
        }

        prefix_set.insert(prefix);
    }
}