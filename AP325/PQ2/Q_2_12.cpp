#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d021

int n, m, k, ans = INT_MIN;
vector<vector<int>> mat;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input() 
{
    scanf("%d", &k);
    scanf("%d %d", &m, &n);
    mat.resize(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void find_ans() 
{
    for (int r1 = 0; r1 < m; ++r1) {

        vector<int> col_sum(n);

        for (int r2 = r1; r2 < m; ++r2) {

            int prefix = 0;
            set<int> prefix_sums({0});

            for (int i = 0; i < n; ++i) {

                col_sum[i] += mat[r2][i];
                prefix += col_sum[i];

                // prefix - target <= K --> prefix - K <= target
                auto it = prefix_sums.lower_bound(prefix - k);

                if (it != prefix_sums.end()) {
                    ans = max(ans, prefix - *it);
                }

                prefix_sums.insert(prefix);
            }
        }
    }
}