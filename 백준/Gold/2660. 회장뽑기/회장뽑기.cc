#include <bits/stdc++.h>
using namespace std;
#define INF 400000000

int N;
int rel[51][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            rel[i][j] = INF;
        }
    }

    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;

        rel[a][b] = 1;
        rel[b][a] = 1;
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (rel[j][i] == INF) continue;
            for (int k=1; k<=N; k++){
                if (rel[i][k] == INF) continue;
                if (rel[j][k] > rel[j][i] + rel[i][k]) rel[j][k] = rel[j][i] + rel[i][k];
            }
        }
    }

    int ans[51] = {};
    int mn = INF;
    int cnt = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i == j) continue;
            ans[i] = max(ans[i], rel[i][j]);
        }
        if (mn > ans[i]) {
            mn = ans[i];
            cnt = 1;
        }
        else if (mn == ans[i]) 
            cnt++;
    }

    cout << mn << " " << cnt << "\n";

    for (int i=1; i<=N; i++) {
        if (ans[i] == mn) cout << i << " ";
    }

    return 0;
}