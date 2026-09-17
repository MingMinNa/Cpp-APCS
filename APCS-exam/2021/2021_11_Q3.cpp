#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=g597 (3. 生產線)

typedef long long LL;

int n, m;
LL ans = 0;
vector<LL> vec, t_vec;

void read_input();
void find_ans();


int main()
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &n, &m);
    vec.resize(n + 2);
    t_vec.resize(n + 1);

    LL l, r, w;

    for (int i = 0; i < m; ++i) {

        scanf("%lld %lld %lld", &l, &r, &w);
        
        vec[l] += w;
        vec[r + 1] -= w;
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &t_vec[i]);
    }
}

void find_ans()
{
    for (int i = 1; i <= n; ++i) {
        vec[i] += vec[i - 1];
    }
    
    sort(vec.begin() + 1, vec.begin() + n + 1, greater<LL>());
    sort(t_vec.begin() + 1, t_vec.end());

    for (int i = 1; i <= n; ++i){
		ans += (vec[i] * t_vec[i]);
	}
}