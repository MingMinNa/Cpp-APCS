#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=o079 (4. 最佳選擇)

int n, k, prefix_sum = 0, prefix_diff = 0;
vector<int> vec;
unordered_map<int, vector<pair<int, int>>> M;

void read_input();
void find_ans();


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
}

void read_input()
{
    cin >> n >> k;
    vec.resize(n + 1);
    M[0].push_back({0, 0});

    for (int i = 1; i <= n; i++) {

        cin >> vec[i];

        prefix_sum += vec[i];
        prefix_diff += (vec[i] % 2) ? (-1) : (1);

        if (prefix_sum > k) continue;
        M[prefix_diff].push_back({i, prefix_sum});
    }
}

void find_ans()
{
    int ans = (M[0].empty() ? 0 : M[0].back().second);
    int suffix_sum = 0, suffix_diff = 0;

    for (int i = n; i >= 1; i--) {

        suffix_sum += vec[i];
        suffix_diff += (vec[i] % 2 ? -1 : 1);

        vector<pair<int, int>> &endpts = M[-suffix_diff];

        int l = 0;
        int r = upper_bound(endpts.begin(), endpts.end(), make_pair(i, -1)) - endpts.begin();

        while (l < r) {

            int mid = (l + r) >> 1;

            if (endpts[mid].second + suffix_sum > k) r = mid;
            else                                     l = mid + 1;
        }

        if (l > 0) {
            ans = max(ans, endpts[l - 1].second + suffix_sum);
        }
    }

    cout << ans;
}