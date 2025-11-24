#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

int N, M, X;
int D[1001][1001]; // a->b

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> X;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            D[i][j] = (i == j) ? 0 : INF;
        }
    }

    while (M--) {
        int a, b;
        cin >> a >> b;
        cin >> D[a][b];
    }

    // 플로이드-워셜: O(N^3)
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            for (int k=1; k<=N; k++) {
                D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
            }
        }
    }

    int ans = 0;

    for (int i=1; i<=N; i++) {
        ans = max(ans, D[i][X] + D[X][i]);
    }

    cout << ans;

    return 0;
}