#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=q183 (3. 重組問題)

int n, m, last;
vector<int> vec, max_vec, min_vec;

void read_input();
void find_ans();
void dfs(vector<int> p, vector<int> d, int q);


int main() 
{
    read_input();
    find_ans();

    for (int i = 0; i < n; i++) printf("%d ", min_vec[i]);
    printf("\n");
    for (int i = 0; i < n; i++) printf("%d ",max_vec[i]);
}

void read_input()
{
    scanf("%d", &n);
    m = n * (n - 1) / 2;

    vec.resize(m);
    min_vec.resize(n, 101);
    max_vec.resize(n, 0);

    for (int i = 0; i < m; i++) {
        scanf("%d", &vec[i]);
    }
}

void find_ans()
{
    if (n == 1) {
        printf("0\n0");
        exit(0);
    }

    sort(vec.begin(), vec.end());
    last = vec.back(); 
    vector<int> point({0});
    dfs(point, vec, last);
}

void dfs(vector<int> p, vector<int> d, int q) 
{
    for (int x : p) {

        auto it = find(d.begin(), d.end(), abs(x - q));

        if (it == d.end()) return; 
        d.erase(it);
    }

    p.push_back(q);

    if (d.empty()) { 

        sort(p.begin(), p.end());

        if (p > max_vec) max_vec = p;
        if (p < min_vec) min_vec = p;
        return;
    }

    q = d.back(); 
    dfs(p, d, q); 
    dfs(p, d, last - q);
}