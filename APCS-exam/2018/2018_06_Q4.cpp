#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d064 (4. 反序數量)

typedef long long LL;

int n;
LL ans = 0;
vector<int> vec;

void read_input();
void merge_sort(int start, int end);


int main() 
{
    read_input();
    merge_sort(0, n);
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

void merge_sort(int start, int end)
{
    if (start + 1 >= end) return;

    int mid = (start + end) >> 1;
    merge_sort(start, mid);
    merge_sort(mid, end);

    for (int i = start; i < mid; ++i) {
        auto it = lower_bound(vec.begin() + mid, vec.begin() + end, vec[i]);
        ans += (it - vec.begin() - mid);
    }

    vector<int> 
        left(mid - start + 1, INT_MAX), 
        right(end - mid + 1, INT_MAX);

    for (int i = start; i < mid; ++i) left[i - start] = vec[i];
    for (int i = mid; i < end; ++i)   right[i - mid] = vec[i];

    int l = 0, r = 0;

    for (int i = start; i < end; ++i) {
        
        if (left[l] <= right[r]) {
            vec[i] = left[l ++];
        }
        else {
            vec[i] = right[r ++];
        }
    }
}