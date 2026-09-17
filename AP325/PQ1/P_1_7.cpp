#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d006

const int P = 10009;

int n, counts = 0; 
vector<int> nums;

void read_input();
void recursive(int idx, int prod);


int main() 
{
    read_input();
    recursive(0, 1);
    counts --;
    printf("%d", counts);
}

void read_input()
{
    scanf("%d", &n);
    nums.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }
}

void recursive(int idx, int prod)
{
    if (idx >= n) {
        counts += (prod == 1);
        return;
    }

    recursive(idx + 1, prod);
    recursive(idx + 1, (prod * nums[idx]) % P);
}
