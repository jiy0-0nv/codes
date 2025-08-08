#if 01
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#define INF 100000000

using namespace std;

int N, M, S, D;
vector<pair<int, int>> graph[500];
int dst[500];

vector<int> prevs[500];

int dijkstra() {
	priority_queue<pair<int, int>> pq; // -d, n

	// init
	for (int i = 0; i < N; i++) dst[i] = INF;
	dst[S] = 0;
	pq.push({ 0, S });

	while (!pq.empty()) {
		int d = -pq.top().first;
		int n = pq.top().second;
		pq.pop();

		for (pair<int, int> nxt : graph[n]) {
			int nn = nxt.first;
			int nd = nxt.second;
			if (dst[nn] > d + nd) {
				dst[nn] = d + nd;
				pq.push({ -d - nd, nn });
				prevs[nn].clear();
				prevs[nn].push_back(n);
			}
			else if (dst[nn] == d + nd) {
				prevs[nn].push_back(n);
			}
		}
	}

	if (dst[D] == INF) return -1;
	else return dst[D];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {

		cin >> N >> M;
		if (N == 0) return 0;
		cin >> S >> D;

		for (int i = 0; i < N; ++i) {
			graph[i].clear();
			prevs[i].clear();
		}

		while (M--) {
			int u, v, p;
			cin >> u >> v >> p;
			graph[u].push_back({ v, p });
		}

		if (dijkstra() == -1) {
			cout << "-1\n";
			continue;
		}

		// 경로 삭제
		deque<int> q;
		q.push_back(D);
		vector<bool> vst(N, false);
		vst[D] = true;

		while (!q.empty())
		{
			int t = q.front();
			q.pop_front();
			for (int p : prevs[t]) {
				vector<pair<int, int>> filtered;

				for (auto &e : graph[p]) {
					if (e.first != t) {
						filtered.push_back(e);
					}
				}
				graph[p] = move(filtered);
				if (!vst[p]) {
					vst[p] = true;
					q.push_back(p);
				}
			}
		}

		// 다시 다익스트라
		cout << dijkstra() << "\n";
	}

	return 0;
}
#endif