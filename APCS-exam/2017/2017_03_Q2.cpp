#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c291 (2. 小群體)

int n, group_count = 0;
vector<int> friends;
vector<char> visited;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
    printf("%d", group_count);
}

void read_input() 
{
    scanf("%d", &n);
    visited.resize(n);
    friends.resize(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &friends[i]);
    }
}

void find_ans() 
{
    for (int i = 0; i < n; ++i) {

        if (visited[i]) 
            continue;

        group_count ++;
        int u = i;

        do {
            visited[u] = true;
            u = friends[u];
        } while (!visited[u]);
    }
}