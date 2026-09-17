#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d026

bool check(string str);


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    while (cin >> str) {
        printf(check(str) ? ("yes\n") : ("no\n"));
    }
}

bool check(string str)
{
    stack<char> stk;
    unordered_map<char, char> right_char = {
        {'}', '{'},
        {']', '['},
        {')', '('}
    };
    
    for (auto &c : str) {

        if (right_char.count(c) == 0) {
            stk.push(c);
            continue;
        }

        if (stk.empty() || right_char[c] != stk.top()) return false;
        stk.pop();
    }

    return stk.empty();
}