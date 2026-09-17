#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=o078 (3. 缺字問題)

int L;
string K, S;
set<string> st;

void read_input();
void find_ans();
void dfs(string &str, int idx);


int main()
{
    read_input();
    find_ans();
}

void read_input()
{
    cin >> K >> L >> S;
}

void find_ans()
{
    string str(L, '0');
    dfs(str, 0);

    for (int i = 0, size = S.size(); i <= size - L; i++) {
        
        string ss = S.substr(i, L);
        
        if (st.find(ss) != st.end()) {
            st.erase(ss);
        }
    }
    
    cout << *st.begin();
}

void dfs(string &str, int idx)
{
    if (idx == L) {
        st.insert(str);
        return;
    }

    for (int i = 0, size = K.size(); i < size; ++i) {
        str[idx] = K[i];
        dfs(str, idx + 1);
    }
}