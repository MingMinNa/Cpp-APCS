#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=e288 (3. 互補CP)

typedef long long LL;

int n, m;
LL ans = 0;
map<LL, int> record;

void read_input();
inline int mapping(char ch);
LL to_key(string str);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    cout << ans;
}

void read_input() 
{
    cin >> m >> n;
    
    LL key;
    string str;
    
    for (int i = 0; i < n; ++i) {
        
        cin >> str;

        key = to_key(str);
        ans += record[(1llu << m) - key - 1];
        record[key] ++;
    }
}

inline int mapping(char ch) 
{
    if ('A' <= ch && ch <= 'Z')  return ch - 'A';
    else                         return ch - 'a' + 26;
}

LL to_key(string str) 
{
    LL key = 0;
    
    for (const auto &ch : str) {
        int idx = mapping(ch);
        key |= (1ll << idx);
    }

    return key;
}