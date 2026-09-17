#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=b964 (1. 成績指標)

int n, targets[2] = {INT_MIN, INT_MAX};
vector<int> scores;

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{
    scanf("%d", &n);
    scores.resize(n);

    for (int i = 0; i < n; ++i) {

        scanf("%d", &scores[i]);
        
        if (scores[i] >= 60) targets[1] = min(targets[1], scores[i]);
        else                targets[0] = max(targets[0], scores[i]);
    }
}

void find_ans() 
{
    sort(scores.begin(), scores.end());

    for (auto &s : scores) printf("%d ", s);
    printf("\n");

    if (targets[0] == INT_MIN) printf("best case\n");
    else                       printf("%d\n", targets[0]);

    if (targets[1] == INT_MAX) printf("worst case\n");
    else                       printf("%d\n", targets[1]);
}