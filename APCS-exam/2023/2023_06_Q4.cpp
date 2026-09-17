#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=k734 (4. 開啟寶盒)

typedef long long LL;

int n, m, k, t;
queue<int> Q;
vector<int> box_count;
vector<char> have_keys;
vector<vector<int>> box_give, key_open;

void read_input();
LL find_ans();


int main()
{
    read_input();
    printf("%lld\n", find_ans());
}

void read_input()
{
    scanf("%d %d %d %d", &n, &m, &k, &t);

    box_give.resize(n);
    key_open.resize(m + 1);
    box_count.resize(n, k);
    have_keys.resize(m + 1, 0);

    int key;

    for (int i = 0; i < t; i++) {

        scanf("%d", &key);

        if (have_keys[key] == 0) {
            have_keys[key] = 1;
            Q.push(key);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &key);
            key_open[key].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &key);
            box_give[i].push_back(key);
        }
    }
}

LL find_ans()
{
    LL ans = 0;

    while (!Q.empty()) {

        int key = Q.front(); Q.pop();

        for (int box : key_open[key]) {
            box_count[box] --;

            if (box_count[box] == 0) {
                ans ++;

                for (int give : box_give[box]) {
                    if (have_keys[give] == 0) {
                        have_keys[give] = 1;
                        Q.push(give);
                    }
                }
            }
        }
    }

    return ans;
}