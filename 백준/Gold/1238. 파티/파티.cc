#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

int N, M, X;

vector<pair<int, int>> EF[1001];
vector<pair<int, int>> EB[1001];

int DF[1001];
int DB[1001];

priority_queue<pair<int, int>> pq;

// 다익스트라 2번: O(NlogN)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> X;

    // 초기화
    fill(DF + 1, DF + 1 + N, INF);
    fill(DB + 1, DB + 1 + N, INF);
    DF[X] = 0;
    DB[X] = 0;

    while (M--) {
        int a, b, t;
        cin >> a >> b >> t;

        EF[a].push_back({t, b});
        EB[b].push_back({t, a});
    }

    // forward 방향 다익스트라
    pq.push({0, X});
    while (!pq.empty()) {
        int t = -pq.top().first;
        int n = pq.top().second;
        pq.pop();

        for (auto e : EF[n]) {
            int nt = e.first;
            int nn = e.second;
            if (DF[nn] > DF[n] + nt) {
                DF[nn] = DF[n] + nt;
                pq.push({-DF[nn], nn});
            }
        }
    }

    // backward 방향 다익스트라
    pq.push({0, X});
    while (!pq.empty()) {
        int t = -pq.top().first;
        int n = pq.top().second;
        pq.pop();

        for (auto e : EB[n]) {
            int nt = e.first;
            int nn = e.second;
            if (DB[nn] > DB[n] + nt) {
                DB[nn] = DB[n] + nt;
                pq.push({-DB[nn], nn});
            }
        }
    }

    int ans = 0;

    for (int i=1; i<=N; i++) {
        ans = max(ans, DF[i] + DB[i]);
    }

    cout << ans;
}