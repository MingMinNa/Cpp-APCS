#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=m931 (1. 遊戲選角)

struct Character {
    int a;
    int d;
};

int n;
vector<Character> char_vec(2);

void read_input();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    cout << char_vec[1].a << " " << char_vec[1].d;
}

void read_input() 
{
    cin >> n;

    int a, d;

    auto ability = [](int a, int d) {
        return a * a + d * d;
    };

    for (int i = 0; i < n; ++i) {

        cin >> a >> d;
        
        if (ability(a, d) > ability(char_vec[0].a, char_vec[0].d)) {
            char_vec[1] = char_vec[0];
            char_vec[0] = {a, d};
        }
        else if (ability(a, d) > ability(char_vec[1].a, char_vec[1].d)) {
            char_vec[1] = {a, d};
        }
    }
}