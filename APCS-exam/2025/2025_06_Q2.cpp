#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=q837 (2. 轉盤得分)

int m, n, k, ans = 0;
vector<string> str_vec;
vector<int> curr_ptr;
vector<vector<int>> ops;

void read_input();
void find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
    cout << ans;
}

void read_input() 
{
    cin >> m >> n >> k;

    str_vec.resize(m);
    curr_ptr.resize(m);
    ops.resize(k, vector<int>(m));

    for (int i = 0; i < m; ++i) {
        cin >> str_vec[i];
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ops[i][j];
        }
    }
}

void find_ans() 
{
    for (int i = 0; i < k; ++i) {

        for (int j = 0; j < m; ++j) {
            curr_ptr[j] = (curr_ptr[j] + n - (ops[i][j] % n)) % n;
        } 

        for (int j = 0; j < n; ++j) {

            int max_count = 0;
            vector<int> letter_count(26, 0);

            for (int h = 0; h < m; ++h) {

                char letter = str_vec[h][(curr_ptr[h] + j) % n];
                letter_count[letter - 'a'] ++;
                max_count = max(max_count, letter_count[letter - 'a']);
            }
            
            ans += max_count;
        }
    }
}