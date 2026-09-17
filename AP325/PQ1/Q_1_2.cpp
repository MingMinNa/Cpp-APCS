#include <bits/stdc++.h>
using namespace std;
// https://judge.tcirc.tw/problem/d002

int f();
int g();
int h();
int get_value();


int main()
{
    printf("%d", get_value());
}

int f()
{
    int x = get_value();
    return 2 * x - 3;
}

int g()
{
    int x = get_value();
    int y = get_value();
    return 2 * x + y - 7;
}

int h()
{
    int x = get_value();
    int y = get_value();
    int z = get_value();
    return 3 * x - 2 * y + z;
}

int get_value()
{
    char input[5];
    scanf("%s", input);

    if      (input[0] == 'f') return f();
    else if (input[0] == 'g') return g();
    else if (input[0] == 'h') return h();
    return atoi(input);
}