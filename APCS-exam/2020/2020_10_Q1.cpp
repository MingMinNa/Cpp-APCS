#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=f312 (1. 人力分配)

int n;
int A1, B1, C1;
int A2, B2, C2;

void read_input();
int find_ans();
inline int calc(int A, int B, int C, int n);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    cout << find_ans();
}

void read_input() 
{
    cin >> A1 >> B1 >> C1;
    cin >> A2 >> B2 >> C2;
    cin >> n;
}

int find_ans() 
{
    int ans = INT_MIN;
    
    for (int i = 0; i <= n; ++i) {
        int revenue = calc(A1, B1, C1, i) + calc(A2, B2, C2, n - i);
        ans = max(revenue, ans);
    }

    return ans;
}

inline int calc(int A, int B, int C, int n) 
{
    return A * n * n + B * n + C;
}