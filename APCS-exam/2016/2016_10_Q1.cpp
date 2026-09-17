#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=c294 (1. 三角形辨別)

#define POW_2(x) ((x) * (x))

int lengths[3] = {0};

void read_input();
void find_ans();


int main() 
{
    read_input();
    find_ans();
}

void read_input() 
{
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &lengths[i]);
    }
}

void find_ans() 
{    
    sort(lengths, lengths + 3);
    printf("%d %d %d\n", lengths[0], lengths[1], lengths[2]);

    if (lengths[0] + lengths[1] <= lengths[2]) {
        printf("No");
    }
    else if (POW_2(lengths[0]) + POW_2(lengths[1]) == POW_2(lengths[2])) {
        printf("Right");
    }
    else if (POW_2(lengths[0]) + POW_2(lengths[1]) < POW_2(lengths[2])) {
        printf("Obtuse");
    }
    else {
        printf("Acute");
    }
}