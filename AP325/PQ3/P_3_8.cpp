#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d032

int N, L, ans = 0;
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
    scanf("%d %d", &N, &L);
    vec.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &vec[i]);
    }
}

void find_ans() 
{
    deque<int> max_dq, min_dq;
    int left = 0, right = 0;
    
    for (; right - left + 1 <= L; ++right) {

        while (!max_dq.empty() && max_dq.back() < vec[right]) max_dq.pop_back();
        while (!min_dq.empty() && min_dq.back() > vec[right]) min_dq.pop_back();

        max_dq.push_back(vec[right]);
        min_dq.push_back(vec[right]);
    }

    ans = max(max_dq.front() - min_dq.front(), ans);

    for (; right < N; ++ right) {

        if (max_dq.front() == vec[left]) max_dq.pop_front();
        if (min_dq.front() == vec[left]) min_dq.pop_front();
        
        left ++;

        while (!max_dq.empty() && max_dq.back() < vec[right]) max_dq.pop_back();
        while (!min_dq.empty() && min_dq.back() > vec[right]) min_dq.pop_back();

        max_dq.push_back(vec[right]);
        min_dq.push_back(vec[right]);
        ans = max(max_dq.front() - min_dq.front(), ans);
    }
}