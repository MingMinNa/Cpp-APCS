#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d074

typedef long long LL;

LL ans = 0;
string DNA_1, DNA_2;
map<pair<int,int>, LL> record;

void read_input();
LL local_alignment(size_t index_1, size_t index_2);


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    local_alignment(0, 0);
    printf("%lld\n", ans);
}

void read_input() 
{
    cin >> DNA_1 >> DNA_2;
}

LL local_alignment(size_t index_1, size_t index_2) 
{
    if (index_1 >= DNA_1.size() || index_2 >= DNA_2.size())
        return 0ll;

    if (record.count({index_1, index_2}))
        return record[{index_1, index_2}];

    LL t1 = (DNA_1[index_1] == DNA_2[index_2]) ?
        local_alignment(index_1 + 1, index_2 + 1) + 8 :
        local_alignment(index_1 + 1, index_2 + 1) - 5 ;
    
    LL t2 = max(
        local_alignment(index_1 + 1, index_2),
        local_alignment(index_1, index_2 + 1)
    ) - 3;

    record[{index_1, index_2}] = max(max(t1, t2), 0ll);
    ans = max(ans, record[{index_1, index_2}]);
    
    return record[{index_1, index_2}];
}