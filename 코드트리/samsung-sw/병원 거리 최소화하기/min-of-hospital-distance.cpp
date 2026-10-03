#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int N, M;
// int board[51][51];

vector<pair<int, int> > hos;
vector<pair<int, int> > per;

int selected[13];

int ans = INF;

int calDist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void selecthos(int idx, int cnt) {
    if (cnt == M) {
        int totalD = 0;

        for (int p = 0; p < per.size(); p++) {
            int minD = INF;

            for (int i = 0; i < M; i++) {
                int h = selected[i];
                minD = min(minD, calDist(per[p], hos[h]));
            }

            totalD += minD;
        }

        ans = min(ans, totalD);
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
            int t;
            cin >> t;
            if (t == 1) per.push_back({r, c});
            else if (t == 2) hos.push_back({r, c});
        }
    }

    selecthos(0, 0);

    cout << ans;

    return 0;
}