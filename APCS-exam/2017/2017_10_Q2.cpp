#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c462 (2. 交錯字串)

int k;
string s;

void read_input();
int find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    read_input();
    cout << find_ans();
}

void read_input() 
{
    cin >> k >> s;
}

int find_ans() 
{
    vector<int> vec;
    bool upper = false;
    int cont_ch = 0;

    for (const char &c : s) {
        
        if ((bool)isupper(c) != upper) {
            vec.push_back(cont_ch);
            cont_ch = 1;
            upper = !upper;
        }
        else {
            cont_ch ++;
        }
    }

    vec.push_back(cont_ch);

    int ans = 0, length = 0;

    for (int i = 0, size = vec.size(); i < size; ++i) {

        if (vec[i] == k) {
            length += k;
            ans = max(ans, length);
        }
        else if (vec[i] > k) {
            ans = max(ans, length + k);
            length = k;
        }
        else {
            length = 0;
        }
    }

    return ans;
}