#if 01
#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999

using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int dst[20001];

priority_queue<pair<int, int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E >> K;

	for (int i = 0; i <= V; i++) dst[i] = INF;

	while (E--) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ w, v }); // 가중치, 정점 순!!
	}

	dst[K] = 0;
	pq.push({ 0, K }); // -거리, 정점으로 저장

	while (!pq.empty()) {
		int d = -pq.top().first;
		int n = pq.top().second;
		pq.pop();

		for (pair<int, int> p : graph[n]) {
			int nxt = p.second;
			int w = p.first;
			if (dst[nxt] > d + w) {
				dst[nxt] = d + w;
				pq.push({ -dst[nxt], nxt });
			}

		}
	}

	for (int i = 1; i <= V; i++) {
		int sd = dst[i];
		if (sd == INF) cout << "INF\n";
		else cout << sd << "\n";
	}

	return 0;
}
#endif