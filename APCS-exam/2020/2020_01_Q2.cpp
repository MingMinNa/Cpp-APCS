#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=h027 (2. 矩陣總和)

typedef long long LL;

int s, t, n, m, r;
LL ans_count = 0, ans_diff = LLONG_MAX, s_sum = 0;
vector<vector<LL>> prefix_mat;
vector<vector<int>> b_mat, s_mat;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();

    if (ans_count > 0) cout << ans_count << endl << ans_diff;
    else               cout << 0 << endl << -1;
}

void read_input() 
{
    scanf("%d %d %d %d %d", &s, &t, &n, &m, &r);
    
    s_mat.resize(s, vector<int>(t));
    b_mat.resize(n + 2, vector<int>(m + 2));
    prefix_mat.resize(n + 2, vector<LL>(m + 2));

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < t; ++j) {
            scanf("%d", &s_mat[i][j]);
            s_sum += s_mat[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= m; ++j) {
            scanf("%d", &b_mat[i][j]);
            prefix_mat[i][j] = b_mat[i][j];
            prefix_mat[i][j] += prefix_mat[i][j - 1];
        }
        
        for (int j = 1; j <= m; ++j) {
            prefix_mat[i][j] += prefix_mat[i - 1][j];
        }
    }
}

void find_ans() 
{
    for (int i = 1; i <= n - s + 1; ++i) {
        for (int j = 1; j <= m - t + 1; ++j) {
            
            int diff_count = 0;
            
            for (int k = 0; k < s; ++k) {
                for (int l = 0; l < t; ++l) {
                    diff_count += (b_mat[i + k][j + l] != s_mat[k][l]);
                }
            }

            if (diff_count > r) continue;

            ans_count ++;
            
            LL b_sum = 
                prefix_mat[i + s - 1][j + t - 1] 
                - prefix_mat[i + s - 1][j - 1] 
                - prefix_mat[i - 1][j + t - 1] 
                + prefix_mat[i - 1][j - 1];

            if (abs(b_sum - s_sum) < ans_diff) {
                ans_diff = abs(b_sum - s_sum);
            }
        }
    }
}