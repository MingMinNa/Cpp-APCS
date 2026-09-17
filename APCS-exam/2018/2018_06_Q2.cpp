#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=e294 (2. 完全奇數)

typedef long long LL;

string N;

LL find_ans(string N_str);
LL find_lss(string N_str);
LL find_grt(string N_str);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N) {
        cout << find_ans(N) << endl;
    }
}

LL find_ans(string N_str) 
{
    return min(
        find_grt(N_str) - stoll(N_str), 
        stoll(N_str) - find_lss(N_str)
    );
}

LL find_lss(string N_str) 
{
    if (stoll(N_str) <= 0) return 0;

    LL less = 0;
    bool lss_same = true;
    size_t s = N_str.size();

    for (int i = 0; i < s; ++i) {

        int digit = N_str[i] - '0';

        /* Special Case */
        if (lss_same && digit == 0) {
            lss_same = false;
            less = find_lss(to_string(less - 1));
        }

        if (lss_same && digit % 2 == 1) {
            less = less * 10 + digit;
        }
        else if (lss_same) {
            lss_same = false;
            less = less * 10 + digit - 1;
        }
        else {
            less = less * 10 + 9;
        }
    }

    return less;
}

LL find_grt(string N_str) 
{
    LL greater = 0;
    bool grt_same = true;
    size_t s = N_str.size();

    for (int i = 0; i < s; ++i) {

        int digit = N_str[i] - '0';

        if (grt_same && digit % 2 == 1) {
            greater = greater * 10 + digit;
        }
        else if (grt_same) {
            grt_same = false;
            greater = greater * 10 + digit + 1;
        }
        else {
            greater = greater * 10 + 1;
        }
    }
    
    return greater;
}