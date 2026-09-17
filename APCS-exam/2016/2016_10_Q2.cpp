#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c295 (2. 最大和)

int n, m;
vector<vector<int>> groups;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{    
    scanf("%d %d", &n, &m);
    groups.resize(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &groups[i][j]);
        }
    }
}

void find_ans() 
{
    int total = 0;
    vector<int> maxi_vec;
    vector<int> divisable;

    for (int i = 0; i < n; ++i) {

        int maxi = INT_MIN;
        
        for (int j = 0; j < m; ++j) {
            maxi = max(maxi, groups[i][j]);
        }
        
        maxi_vec.push_back(maxi);
        total += maxi;
    }

    for (int i = 0; i < n; ++i) {
        if (total % maxi_vec[i] == 0) {
            divisable.push_back(maxi_vec[i]);
        }
    }

    int size = divisable.size();
    
    printf("%d\n", total);
    
    if (size == 0) {
        printf("-1");
        return;
    }

    printf("%d", divisable[0]);
    for (int i = 1; i < size; ++i) {
        printf(" %d", divisable[i]);
    }
}