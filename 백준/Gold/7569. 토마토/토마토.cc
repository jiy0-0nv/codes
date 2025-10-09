#include <bits/stdc++.h>
using namespace std;
#include <deque>

int M, N, H;
int tmt[100][100][100];
int rem;
deque<array<int, 3>> q = {};
int ans=0;
int DIR[6][3] = {{-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1}};

void bfs(){
    int h = q.front()[0];
    int n = q.front()[1];
    int m = q.front()[2];
    int day = tmt[h][n][m];
    q.pop_front();

    if (ans < day - 1) ans = day - 1;

    for (auto d:DIR){
        int nh = h+d[0];
        int nn = n+d[1];
        int nm = m+d[2];
        if (nh>=0 && nh<H && nn>=0 && nn<N && nm>=0 && nm<M && tmt[nh][nn][nm]==0){
            tmt[nh][nn][nm] = day + 1;
            rem--;
            q.push_back({nh, nn, nm});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N >> H;
    rem = M * N * H;

    for (int i=0; i<H; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<M; k++){
                int t;
                cin >> t;
                tmt[i][j][k] = t;
                if (t==1 || t==-1) rem--;
                if (t==1) q.push_back({i, j, k});
            }
        }
    }

    while (!q.empty()){
        bfs();
    }

    if (rem==0) cout << ans;
    else cout << -1;

    return 0;
}