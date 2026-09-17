#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=q184 (4. 分組開會)

typedef long long LL;

int n, k;
LL ans = LLONG_MAX;
vector<LL> p, d, p_min;

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
    scanf("%d %d", &n, &k);
    
    p.resize(n);
    d.resize(n);
    p_min.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &p[i]);
    }
}

void find_ans()
{
    sort(p.begin(), p.begin() + n);
    
    int left = 0, right = k - 1, mid = k / 2;
    d[right] = 0;

    for (int i = 0; i <= right; i++) {
        d[right] += abs(p[i] - p[mid]);
    }

    for (left++, right++, mid++; right < n; left++, right++, mid++) {
        d[right] = d[right - 1] - (p[mid - 1] - p[left - 1]);
        d[right] += (p[mid] - p[mid - 1]) * ((mid - left) - (right - mid)) + (p[right] - p[mid]);
    }

    p_min[k - 1] = d[k - 1];

    for (int i = k; i < n; i++) {
        p_min[i] = min(p_min[i - 1], d[i]);
    }

    for (int i = 2 * k - 1; i < n; i++) {
        ans = min(ans, d[i] + p_min[i - k]);
    }
}