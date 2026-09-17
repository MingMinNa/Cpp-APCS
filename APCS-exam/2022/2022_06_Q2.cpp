#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=i400 (2. 字串解碼)

int m, n;
string str;
vector<string> bits;

void read_input();
void find_ans();
string decode(string str, string bit);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << str;
}

void read_input() 
{
    cin >> m >> n;
    bits.resize(m);

    for (int i = 0; i < m; ++i) cin >> bits[i];
    cin >> str;
}

void find_ans() 
{
    for (int i = m - 1; i >= 0; --i) {
        str = decode(str, bits[i]);
    }
}

string decode(string str, string bit) 
{
    int count_1 = 0;
    string res = "";

    for (int i = n - 1; i >= 0; --i) {

        if (bit[i] == '0') {  
            res.insert(res.begin(), str[i]);
        }
        else {
            res.push_back(str[i]);
            count_1 ++;
        }
    }

    if (count_1 % 2 == 1 && n % 2 == 1) {
        res = \
            res.substr(n / 2 + 1, n / 2) + 
            res[n / 2] + 
            res.substr(0, n / 2);
    }
    else if (count_1 % 2 == 1) {
        res = \
            res.substr(n / 2, n / 2) + 
            res.substr(0, n / 2);
    }

    return res;
}