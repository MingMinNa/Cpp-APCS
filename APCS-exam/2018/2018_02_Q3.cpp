#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f638 (3. 支點切割)

typedef long long LL;

int n, k;
vector<LL> vec;

void read_input();
LL cut(int left, int right, int level);


int main() 
{
    read_input();
    printf("%lld\n", cut(1, n, k));
}

void read_input() 
{
    scanf("%d %d", &n, &k);
    vec.resize(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &vec[i]);
        vec[i] += vec[i - 1];
    }
}

LL cut(int left, int right, int level) 
{
    if (level <= 0 || right - left <= 1)  return 0ll;

    LL partial_sum = vec[right] - vec[left - 1];
    LL curr_val = (-1) * (vec[left] - vec[left - 1]);
    int cut_point = left + 1;

    for (int i = left + 1; i < right; ++i) {
        curr_val += (vec[right] - vec[i]);
    }
    
    for (int i = left + 2; i < right; ++i) {

        if (abs(curr_val - partial_sum) < abs(curr_val)) {
            curr_val -= partial_sum;
            cut_point = i;
        }
    }

    return \
        vec[cut_point] - vec[cut_point - 1] + 
        cut(left, cut_point - 1, level - 1) + 
        cut(cut_point + 1, right, level - 1);
}