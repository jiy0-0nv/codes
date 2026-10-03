#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;

int N, M;
int board[51][51];

vector<pair<int, int>> hos;
vector<pair<int, int>> vir;

// h번 병원 ~ v번 바이러스 거리
int hosDist[10][2500];

int selected[10];

int ans = INF;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void bfs(int h) {
    int dist[51][51];

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            dist[r][c] = -1;
        }
    }

    queue<pair<int, int>> q;

    int sr = hos[h].first;
    int sc = hos[h].second;

    dist[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N)
                continue;

            if (board[nr][nc] == 1 || dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    for (int v = 0; v < vir.size(); v++)
        hosDist[h][v] = dist[vir[v].first][vir[v].second];
}

void selecthos(int idx, int cnt) {
    if (cnt == M) {
        int maxTime = 0;

        for (int v = 0; v < vir.size(); v++) {
            int minTime = INF;

            for (int i = 0; i < M; i++) {
                int h = selected[i];
                if (hosDist[h][v] != -1)
                    minTime = min(minTime, hosDist[h][v]);
            }

            if (minTime == INF) return;

            maxTime = max(maxTime, minTime);
        }
        ans = min(ans, maxTime);
        return;
    }

    for (int i = idx; i < hos.size(); i++) {
        selected[cnt] = i;
        selecthos(i + 1, cnt + 1);
    }
}


int main() {
    cin >> N >> M;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];

            if (board[r][c] == 0)
                vir.push_back({r, c});
            else if (board[r][c] == 2)
                hos.push_back({r, c});
        }
    }

    for (int h = 0; h < hos.size(); h++)
        bfs(h);

    selecthos(0, 0);

    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}