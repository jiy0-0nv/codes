#include <bits/stdc++.h>
using namespace std;

int N, M;
int ngraph[501][501];
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> ngraph[i][j];
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            // 1x4
            if (j + 3 < M) {
                int t = ngraph[i][j] + ngraph[i][j+1] + ngraph[i][j+2] + ngraph[i][j+3];
                ans = max(ans, t);
            }
            // 4x1
            if (i + 3 < N) {
                int t = ngraph[i][j] + ngraph[i+1][j] + ngraph[i+2][j] + ngraph[i+3][j];
                ans = max(ans, t);
            }
            // 2x2
            if (i + 1 < N && j + 1 < M) {
                int t = ngraph[i][j] + ngraph[i][j+1] + ngraph[i+1][j] + ngraph[i+1][j+1];
                ans = max(ans, t);
            }
            // 2x3
            if (i + 1 < N && j + 2 < M) {
                int t = ngraph[i][j] + ngraph[i][j+1] + ngraph[i][j+2] + ngraph[i+1][j];
                ans = max(ans, t);
                t = ngraph[i][j] + ngraph[i][j+1] + ngraph[i][j+2] + ngraph[i+1][j+1];
                ans = max(ans, t);
                t = ngraph[i][j] + ngraph[i][j+1] + ngraph[i][j+2] + ngraph[i+1][j+2];
                ans = max(ans, t);

                t = ngraph[i+1][j] + ngraph[i+1][j+1] + ngraph[i+1][j+2] + ngraph[i][j];
                ans = max(ans, t);
                t = ngraph[i+1][j] + ngraph[i+1][j+1] + ngraph[i+1][j+2] + ngraph[i][j+1];
                ans = max(ans, t);
                t = ngraph[i+1][j] + ngraph[i+1][j+1] + ngraph[i+1][j+2] + ngraph[i][j+2];
                ans = max(ans, t);

                t = ngraph[i][j] + ngraph[i][j+1] + ngraph[i+1][j+1] + ngraph[i+1][j+2];
                ans = max(ans, t);
                t = ngraph[i][j+1] + ngraph[i][j+2] + ngraph[i+1][j] + ngraph[i+1][j+1];
                ans = max(ans, t);
            }
            // 3x2
            if (i + 2 < N && j + 1 < M) {
                int t = ngraph[i][j] + ngraph[i+1][j] + ngraph[i+2][j] + ngraph[i][j+1];
                ans = max(ans, t);
                t = ngraph[i][j] + ngraph[i+1][j] + ngraph[i+2][j] + ngraph[i+1][j+1];
                ans = max(ans, t);
                t = ngraph[i][j] + ngraph[i+1][j] + ngraph[i+2][j] + ngraph[i+2][j+1];
                ans = max(ans, t);

                t = ngraph[i][j+1] + ngraph[i+1][j+1] + ngraph[i+2][j+1] + ngraph[i][j];
                ans = max(ans, t);
                t = ngraph[i][j+1] + ngraph[i+1][j+1] + ngraph[i+2][j+1] + ngraph[i+1][j];
                ans = max(ans, t);
                t = ngraph[i][j+1] + ngraph[i+1][j+1] + ngraph[i+2][j+1] + ngraph[i+2][j];
                ans = max(ans, t);

                t = ngraph[i][j] + ngraph[i+1][j] + ngraph[i+1][j+1] + ngraph[i+2][j+1];
                ans = max(ans, t);
                t = ngraph[i][j+1] + ngraph[i+1][j+1] + ngraph[i+1][j] + ngraph[i+2][j];
                ans = max(ans, t);
            }
        }
    }

    cout << ans;

    return 0;
}