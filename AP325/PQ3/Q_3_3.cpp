#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d027

#define IS_MUL_DIV(x) ((x) == '*' || (x) == '/')
#define IS_ADD_SUB(x) ((x) == '+' || (x) == '-')

string infix;
stack<int> val_stk;

void read_input();
int find_ans();
int calculate(char op);
string infix_to_postfix();


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    printf("%d", find_ans());
}

void read_input()
{
    cin >> infix;
}

int find_ans()
{
    string postfix = infix_to_postfix();

    for (auto &e : postfix) {
        if (isdigit(e)) val_stk.push(e - '0');
        else            val_stk.push(calculate(e));
    }

    return val_stk.top();
}

int calculate(char op)
{
    int val_2 = val_stk.top(); val_stk.pop();
    int val_1 = val_stk.top(); val_stk.pop();

    switch (op)
    {
        case '+': return val_1 + val_2;
        case '-': return val_1 - val_2;
        case '*': return val_1 * val_2;
        case '/': return val_1 / val_2;
        default:  return 0;
    }
}

string infix_to_postfix()
{
    string postfix = "";
    stack<char> op_stk;

    auto precedence = [](char op) {
        if      (IS_MUL_DIV(op)) return 2;
        else if (IS_ADD_SUB(op)) return 1;
        return 0;
    };

    for (auto &e : infix) {

        if (isdigit(e)) {
            postfix.push_back(e);
            continue;
        }

        while (!op_stk.empty() && precedence(op_stk.top()) >= precedence(e)) {
            postfix.push_back(op_stk.top());
            op_stk.pop();
        }

        op_stk.push(e);
    }

    while (!op_stk.empty()) {
        postfix.push_back(op_stk.top());
        op_stk.pop();
    }
    
    return postfix;
}