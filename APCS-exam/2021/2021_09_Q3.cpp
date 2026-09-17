#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=g277 (3. 幸運數字)

typedef long long LL;

int n, root;
stack<int> stk;
vector<int> arr, left_child, right_child;
vector<LL> subtree_sum;

void read_input();
LL tree_sum(int root);
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
    cin >> n;

    arr.resize(n);
    left_child.resize(n, -1);
    right_child.resize(n, -1);
    subtree_sum.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {

        while (!stk.empty() && arr[stk.top()] > arr[i]) {
            left_child[i] = stk.top();
            stk.pop();
        }
        
        if (!stk.empty()) {
            right_child[stk.top()] = i;
        }

        stk.push(i);
    }

    while (stk.size() > 1) stk.pop();

    root = stk.top();
    tree_sum(root);
}

LL tree_sum(int root) 
{
    if (left_child[root]  != -1) subtree_sum[root] += tree_sum(left_child[root]);
    if (right_child[root] != -1) subtree_sum[root] += tree_sum(right_child[root]);

    subtree_sum[root] += arr[root];
    return subtree_sum[root];
}

void find_ans() 
{
    int curr = root;

    auto is_leaf = [&](int i) {
        return (left_child[i] == -1) && (right_child[i] == -1);
    };

    while (!is_leaf(curr)) {

        int left_idx = left_child[curr], right_idx = right_child[curr];
        LL left_sum  = (left_idx  == -1) ? (0) : (subtree_sum[left_idx] );
        LL right_sum = (right_idx == -1) ? (0) : (subtree_sum[right_idx]);

        if (right_sum >= left_sum) curr = right_idx;
        else                       curr = left_idx;
    }
    
    cout << arr[curr];
}