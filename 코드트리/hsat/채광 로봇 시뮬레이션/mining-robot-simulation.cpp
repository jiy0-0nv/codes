#include <bits/stdc++.h>

using namespace std;

const int MIN_INT = -2e9;

int N, T;
vector<vector<int>> grid;
vector<vector<int>> dp1;
vector<vector<int>> dp2;
vector<vector<vector<int>>> max_len;

int main() {
    cin.tie(NULL);

    cin >> N >> T;

    grid.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    dp1.assign(N, vector<int>(N, MIN_INT));
    dp1[0][0] = grid[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0 && dp1[i - 1][j] != MIN_INT) 
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j] + grid[i][j]);
            if (j > 0 && dp1[i][j - 1] != MIN_INT) 
                dp1[i][j] = max(dp1[i][j], dp1[i][j - 1] + grid[i][j]);
        }
    }

    dp2.assign(N, vector<int>(N, MIN_INT));
    dp2[N - 1][N - 1] = grid[N - 1][N - 1];
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (i < N - 1 && dp2[i + 1][j] != MIN_INT) 
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j] + grid[i][j]);
            if (j < N - 1 && dp2[i][j + 1] != MIN_INT) 
                dp2[i][j] = max(dp2[i][j], dp2[i][j + 1] + grid[i][j]);
        }
    }

    max_len.assign(T + 1, vector<vector<int>>(N, vector<int>(N, MIN_INT)));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            max_len[0][i][j] = grid[i][j];
        }
    }

    for (int k = 1; k <= T; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i + 1 < N && max_len[k - 1][i + 1][j] != MIN_INT) 
                    max_len[k][i][j] = max(max_len[k][i][j], grid[i][j] + max_len[k - 1][i + 1][j]);
                if (j + 1 < N && max_len[k - 1][i][j + 1] != MIN_INT) 
                    max_len[k][i][j] = max(max_len[k][i][j], grid[i][j] + max_len[k - 1][i][j + 1]);
            }
        }
    }

    int ans = dp1[N - 1][N - 1];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (max_len[T][i][j] != MIN_INT && dp1[i][j] != MIN_INT && dp2[i][j] != MIN_INT) {
                int total = dp1[i][j] + max_len[T][i][j] + dp2[i][j] - grid[i][j];
                ans = max(ans, total);
            }
        }
    }

    cout << ans;

    return 0;
}