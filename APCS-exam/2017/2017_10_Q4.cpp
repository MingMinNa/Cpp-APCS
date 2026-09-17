#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c471 (4. 物品堆疊)

typedef long long LL;

struct Item {
    LL f, w;
};

int n;
vector<Item> items;

void read_input();
LL find_ans();


int main() 
{
    read_input();
    printf("%lld", find_ans());
}

void read_input() 
{
    scanf("%d", &n);
    items.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &items[i].w);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &items[i].f);
    }
}

LL find_ans() 
{
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.w * b.f < b.w * a.f;
    });

    LL ans = 0, weights = 0;
    
    for (int i = 0; i < n; ++i) {
        ans += weights * items[i].f;
        weights += items[i].w;
    }

    return ans;
}