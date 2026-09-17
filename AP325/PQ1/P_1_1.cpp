#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d001

int f();
int g();
int get_value();


int main()
{
    printf("%d", get_value());
}

int f()
{
    int x = get_value();
    return 2 * x - 1;
}

int g()
{
    int x = get_value();
    int y = get_value();
    return x + 2 * y - 3;
}

int get_value()
{
    char input[5];
    scanf("%s", input);

    if      (input[0] == 'f') return f();
    else if (input[0] == 'g') return g();
    return atoi(input);
}