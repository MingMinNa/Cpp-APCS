#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d016

int m, n, complement_count = 0;
string team;
unordered_set<int> teams;

void read_input();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    read_input();
    cout << complement_count;
}

void read_input() 
{
    cin >> m >> n;

    auto complement = [&](int team_encoding) {
        return (1 << m) - team_encoding - 1;
    };
    
    for (int i = 0; i < n; ++i) {

        cin >> team;

        int team_encoding = 0;

        for (auto &p : team) {
            team_encoding |= (1ll << (p - 'A'));
        }

        auto complement_team = 
            teams.find(complement(team_encoding));

        if (complement_team != teams.end()) complement_count ++;
        else                                teams.insert(team_encoding);
    }
}