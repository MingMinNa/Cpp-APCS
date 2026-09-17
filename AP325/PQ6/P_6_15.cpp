#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d078

int n, ans = 0;
vector<int> vec;

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
        scanf("%d", &vec[i]);
    }
}

void find_ans()
{
    vector<int> last;

    for (int i = 0; i < n; ++i) {

        auto it = lower_bound(last.begin(), last.end(), vec[i]);

        if (it == last.end()) last.push_back(vec[i]);
        else                  *it = vec[i];
    }
    
    ans = (int)last.size();
}