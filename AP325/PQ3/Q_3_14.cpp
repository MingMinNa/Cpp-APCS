#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d038

typedef long long LL;

struct Func {
    LL a, b;
};

int N, m;
LL ans = 0;
vector<LL> x_vec;
vector<Func> func_vec;

void read_input();
void find_ans();
bool remove_func(Func func_1, Func func_2, Func func_3);


int main()
{
    read_input();
    find_ans();
    printf("%lld", ans);
}

void read_input()
{
    scanf("%d %d", &N, &m);
    func_vec.resize(N);
    x_vec.resize(m);

    for (int i = 0; i < N; ++i) {
        scanf("%lld %lld", &func_vec[i].a, &func_vec[i].b);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%lld", &x_vec[i]);
    }
}

void find_ans()
{
    sort(x_vec.begin(), x_vec.end());
    sort(func_vec.begin(), func_vec.end(), [](const Func &x, const Func &y) {
        return x.a < y.a || (x.a == y.a && x.b < y.b);
    });

    int curr_size = 0;
    vector<Func> new_func;

    for (int i = 0; i < N; ++i) {

        while (curr_size > 0 && new_func[curr_size - 1].a == func_vec[i].a) {
            new_func.pop_back();
            curr_size --;
        }

        while (curr_size >= 2 && remove_func(new_func[curr_size - 2], new_func[curr_size - 1], func_vec[i])) {
            new_func.pop_back();
            curr_size --;
        }

        new_func.push_back(func_vec[i]);
        curr_size ++;
    }
    
    N = curr_size;
    func_vec = move(new_func);

    auto calc_func = [&](int x_idx, int f_idx) {
        return (func_vec[f_idx].a) * x_vec[x_idx] + func_vec[f_idx].b;
    };

    for (int i = 0, j = 0; i < m; ++i) {
        while (j < N - 1 && calc_func(i, j) <= calc_func(i, j + 1)) {
            ++ j;
        }
        ans += calc_func(i, j);
    }
}

bool remove_func(Func func_1, Func func_2, Func func_3)
{
    // a1 * x2 + b1 = a2 * x2 + b2 --> (a1 - a2) * x2 = b2 - b1
    // a1 * x3 + b1 = a3 * x3 + b3 --> (a1 - a3) * x3 = b3 - b1
    
    // x3 <= x2 --> (b3 - b1) * (a1 - a2) <= (b2 - b1) * (a1 - a3);
    return (func_3.b - func_1.b) * (func_1.a - func_2.a) <= (func_2.b - func_1.b) * (func_1.a - func_3.a);
}