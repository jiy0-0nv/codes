#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

int N;
int cost[10][10];
bool vst[10][10];
int ans = 3000;
int DIR[5][2] = {{-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0}};
        
bool canplant(int r, int c){
    if (r == 0 || c == 0 || r == N-1 || c == N-1)
        return false;
    for (auto d:DIR){
        if (vst[r+d[0]][c+d[1]])
            return false;
    }
    return true;
}

void bt(int n, int c){
    if (c >= ans){
        return;
    }
    if (n == 3){
        ans = c;
        return;
    }
    for (int i=1; i<N-1; i++){
        for (int j=1; j<N-1; j++){
            if (canplant(i, j)){
                int nc = c;
                for (auto d:DIR){
                    vst[i+d[0]][j+d[1]] = true;
                    nc += cost[i+d[0]][j+d[1]];
                }
                bt(n+1, nc);
                for (auto d:DIR){
                    vst[i+d[0]][j+d[1]] = false;
                }
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> cost[i][j];
        }
    }

    bt(0, 0);

    cout << ans;

    return 0;
}