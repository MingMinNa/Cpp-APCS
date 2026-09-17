#include <bits/stdc++.h>
using namespace std;
// https://zerojudge.tw/ShowProblem?problemid=o077 (2. 電子畫布)

struct Point {
    int r;
    int c;
    int t;
    int x;
};

int H, W, N;
vector<Point> draw;
vector<vector<int>> canva;

void read_input();
void find_ans();


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    find_ans();
}

void read_input() 
{
    cin >> H >> W >> N;
    canva.resize(H, vector<int>(W));
    draw.resize(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> draw[i].r >> draw[i].c >> draw[i].t >> draw[i].x;
    }
}

void find_ans() 
{
    for (int i = 0; i < N; ++i) {
        
        int r = draw[i].r, c = draw[i].c, t = draw[i].t, x = draw[i].x;
        int r_start = max(0, r - t), r_end = min(H - 1, r + t);

        for (int j = r_start; j <= r_end; ++j) {
            
            int c_start = max(0, c - (t - abs(r - j)));
            int c_end = min(W - 1, c + (t - abs(r - j)));

            for (int k = c_start; k <= c_end; ++k) {
                canva[j][k] += x;
            }
        }
    }
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            printf("%d ", canva[i][j]);
        }
        printf("\n");
    }
}