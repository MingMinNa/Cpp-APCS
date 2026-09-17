#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=k733 (3. 磁軌移動序列)

typedef long long LL;

string str;
queue<int> Q;
pair<pair<int, int>, LL> ans;

void read_input();
pair<pair<int, int>, LL> calc();


int main()
{
    read_input();
    ans = calc();
    printf("%lld", ans.second + abs(10 - ans.first.first));
}

void read_input()
{
    int num;
    char ch;

    while (scanf(" %c", &ch) != EOF) {

        if (ch == 'T') {
            scanf("%d", &num);
            Q.push(num);
        }
        else if (ch == 'L') {
            scanf("%d", &num);
            Q.push(num);
        }
        else {
            Q.push(-1);
        }
    }

    Q.push(-1);
}

pair<pair<int, int>, LL> calc()
{
    int prev = Q.front(), last = Q.front();
    LL total_dist = 0;

    while (Q.front() != -1) {
        
        int curr = Q.front(); Q.pop();

        if (curr >= 10) { // Txx
            total_dist += abs(curr - prev);
            prev = curr;
        }
        else {           // Lx...

            pair<pair<int, int>, LL> loop = calc();
            total_dist += loop.second * curr;
            total_dist += abs(loop.first.first - loop.first.second) * (curr - 1);
            
            if (last < 10) { // this calc() is a loop 
                last = loop.first.first;
            }
            else {
                total_dist += abs(prev - loop.first.first);
            }

            prev = loop.first.second;
        }
    }

    Q.pop();
    return { {last, prev}, total_dist};
}