#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=j606 (2. 造字程式)

int K, Q, R;
string str;
vector<string> str_vec;
vector<vector<int>> P;

void read_input();
void find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
}

void read_input() 
{
    cin >> K >> Q >> R;
    cin >> str;
    P.resize(Q, vector<int>(K));

    for (int i = 0; i < Q; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> P[i][j];
        }
    }
}

void find_ans() 
{
    for (int i = 0; i < Q; ++i) {

        string temp_str(str);

        for (int j = 0; j < K; ++j) {
            temp_str[P[i][j] - 1] = str[j];
        }
        
        str = temp_str;
        str_vec.push_back(str);
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < Q; ++j) {
            cout << str_vec[j][i];
        }
        cout << endl;
    }
}