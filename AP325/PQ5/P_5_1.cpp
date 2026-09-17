#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;

void read_input();
pair<int,int> recursive(int start, int end);


int main()
{
    read_input();
    pair<int, int> min_max = recursive(0, n);
    printf("%d %d", min_max.first, min_max.second);
}

void read_input()
{
    scanf("%d", &n);
    vec.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }
}

pair<int,int> recursive(int start, int end)
{
    if (start + 1 == end)
        return {
            vec[start], 
            vec[start]
        };

    pair<int, int> l_min_max = recursive(start, (end + start) >> 1);
    pair<int, int> r_min_max = recursive((end + start) >> 1, end);
    
    return {
        min(l_min_max.first, r_min_max.first),
        max(l_min_max.second, r_min_max.second),
    };
}