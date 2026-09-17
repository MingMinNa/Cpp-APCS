#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=j607 (3. 先加後乘與函數)

typedef long long LL;

string input;
int curr = 0;

LL eval();
LL eval_f();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> input;
    cout << eval() << endl;
}

LL eval() 
{
    stack<LL> val_stk;
    stack<char> op_stk;
    LL val = 0;

    for (; curr < input.size();) {
        
        if (input[curr] == ',' || input[curr] == ')') {
            break;
        }
        else if (input[curr] == 'f') {
            val = eval_f();
        }
        else if (isdigit(input[curr])) {
            val = val * 10 + input[curr] - '0';
            curr ++;
        }
        else if (input[curr] == '+') {

            val_stk.push(val);
            val = 0;

            while (!op_stk.empty() && op_stk.top() == '+') {

                LL val_2 = val_stk.top(); val_stk.pop();
                LL val_1 = val_stk.top(); val_stk.pop();

                char op = op_stk.top(); op_stk.pop();
                val_stk.push(val_1 + val_2);
            }

            op_stk.push('+');
            curr ++;
        }
        else if (input[curr] == '*') {

            val_stk.push(val);
            val = 0;

            while (!op_stk.empty()) {

                LL val_2 = val_stk.top(); val_stk.pop();
                LL val_1 = val_stk.top(); val_stk.pop();

                char op = op_stk.top();   op_stk.pop();

                if (op == '+') val_stk.push(val_1 + val_2);
                else           val_stk.push(val_1 * val_2);
            }

            op_stk.push('*');
            curr ++;
        }
    }

    val_stk.push(val);

    while (!op_stk.empty()) {

        LL val_2 = val_stk.top(); val_stk.pop();
        LL val_1 = val_stk.top(); val_stk.pop();
        char op = op_stk.top();   op_stk.pop();
        
        if (op == '+') val_stk.push(val_1 + val_2);
        else           val_stk.push(val_1 * val_2);
    }
    
    return val_stk.top();
}

LL eval_f() 
{
    LL max_ele = LLONG_MIN; 
    LL min_ele = LLONG_MAX;
    curr += 2;

    while (true) {

        LL ele = eval();
        max_ele = max(max_ele, ele);
        min_ele = min(min_ele, ele);

        if (input[curr] == ')') break;
        curr ++;
    }

    curr ++;
    return max_ele - min_ele;
}