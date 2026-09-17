#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d031

typedef long long LL;

int n, k;
LL ans_val = 0, ans_count = 0;
vector<int> arr;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%lld\n%lld", ans_val, ans_count);
}

void read_input()
{
    scanf("%d %d", &n, &k);
    arr.resize(n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
}

void find_ans()
{
    int curr_val = 0, left = 0;

    for (int i = 0; i < n; ++i) {
        curr_val += arr[i];

        // (1) linear search
        while (curr_val > k) {
            curr_val -= arr[left];
            left ++;
        }
        
        if (ans_val < curr_val) {
            ans_val = curr_val;
            ans_count = 1;
        }
        else if (ans_val == curr_val) {
            ans_count ++;
        }
    }
}