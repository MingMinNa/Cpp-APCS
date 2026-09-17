#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=q182 (2. 字串操作)

int k, str_size;
string str;
vector<int> ops;

void read_input();
void find_ans();
void op_0();
void op_1();
void op_2();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
}

void read_input() 
{
    cin >> str >> k;
    ops.resize(k);
    str_size = str.size();

    for (int i = 0; i < k; ++i) {
        cin >> ops[i];
    }
}

void find_ans() 
{
    for (int i = 0; i < k; ++i) {
        if      (ops[i] == 0) op_0();
        else if (ops[i] == 1) op_1();
        else                  op_2();
    }

    cout << str;
}

void op_0() 
{
    for (int i = 0; i < str_size; i += 2) {
        swap(str[i], str[i + 1]);
    }
}

void op_1() 
{
    vector<pair<char, char>> str_arr;

    for (int i = 0; i < str_size; i += 2) {
        if (i + 1 == str_size)   break;
        if (str[i] > str[i + 1]) swap(str[i], str[i + 1]);
    }
}

void op_2() 
{
    string temp_str;
    int i = 0, j = str_size / 2;

    for (; i < str_size / 2 || j < str_size; ++i, ++j) {
        if (i < str_size / 2) temp_str.push_back(str[i]);
        if (j < str_size)     temp_str.push_back(str[j]);
    }
    
    str = temp_str;
}