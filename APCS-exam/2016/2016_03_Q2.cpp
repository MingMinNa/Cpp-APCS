#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=b965 (2. 矩陣轉換)

int r, n, m;
vector<int> ops;
vector<vector<int>> mat;

void read_input();
void find_ans();
void rotate();
void flip();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{
    scanf("%d %d %d", &n, &m, &r);
    mat.resize(n, vector<int>(m));
    ops.resize(r);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < r; ++i) {
        scanf("%d", &ops[i]);
    }
}

void find_ans() 
{    
    for (int i = r - 1; i >= 0; --i) {
        if (ops[i] == 1) flip();
        else             rotate();
    }
    
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {

        printf("%d", mat[i][0]);
        for (int j = 1; j < m; ++j) {
            printf(" %d", mat[i][j]);
        }

        printf("\n");
    }
}

void rotate() 
{
    vector<vector<int>> new_mat(m, vector<int>(n));

    for (int i = m - 1, k = 0; i >= 0; --i, ++k) {
        for (int j = 0, l = 0; j < n; ++j, ++l) {
            new_mat[k][l] = mat[j][i];
        }
    }

    mat.clear();
    mat = move(new_mat);
    swap(n, m);
}

void flip() 
{
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        swap(mat[i], mat[j]);
    }
}