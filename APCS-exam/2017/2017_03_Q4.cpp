#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c575 (4. 基地台)

int N, K, ans = INT_MAX;
vector<int> P;

void read_input();
void find_ans();
bool check(int diam);


int main() 
{
    read_input();
    find_ans();
    printf("%d", ans);
}

void read_input() 
{
    scanf("%d %d", &N, &K);
    P.resize(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
    }
}

void find_ans() 
{
    sort(P.begin(), P.end());

    int diam = 0;
    
    for (int jump = (P[P.size() - 1] - P[0]) / 2; jump >= 1; jump >>= 1) {
        while (!check(diam + jump)) {
            diam += jump;
        }
    }

    ans = diam + 1;
}

bool check(int diam) 
{
    int k = 1; 
    int end = P[0] + diam;

    for (int i = 0; i < N;) {

        for (int jump = (N - i) / 2; jump >= 1; jump >>= 1) {
            while (i + jump < N && P[i + jump] <= end) {
                i += jump;
            }
        }

        i ++;

        if (i < N) {
            k ++;
            end = P[i] + diam;
        }
    }

    return k <= K;
}