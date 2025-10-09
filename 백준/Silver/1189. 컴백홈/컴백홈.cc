#include <bits/stdc++.h>
using namespace std;

int R, C, K;
bool vst[5][5];
int ans = 0;

int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bt(int x, int y, int c){
    if (c == K){
        if (x == 0 && y == C-1)
            ans++;
        return;
    }
    else if (x == 0 && y == C-1) return;

    for (auto d:DIR){
        if (x+d[0]>=0 && x+d[0]<R && y+d[1]>=0 && y+d[1]<C && vst[x+d[0]][y+d[1]]==false){
            vst[x+d[0]][y+d[1]] = true;
            bt(x+d[0], y+d[1], c+1);
            vst[x+d[0]][y+d[1]] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> K;
    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++){
            char t;
            cin >> t;
            if (t == 'T') vst[i][j] = true;
        }
    }

    vst[R-1][0] = true;
    bt(R-1, 0, 1);

    cout << ans;

    return 0;
}