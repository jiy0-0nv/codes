#include <iostream>
#include <vector>

using namespace std;

int V, E;
vector<int> graph[10001];
vector<int> roots;
int cntcom = 0;

int vstcnt = 0;
int visitOrder[10001];

bool cut[10001];
int cutcnt = 0;

int dfs(int cur, int p) {
	// cur: 현재 노드
	// p: cur의 부모 노드
	int low = visitOrder[cur]; // not root의 단절점 판별용 (p 기준->return용), cur에서 갈 수 있는 가장 낮은 order
	int rootchild = 0; // root의 단절점 판별용 (cur 기준)

	for (int nxt : graph[cur]) {
		// p의 low를 계산하므로 p는 skip
		if (nxt == p) continue;

		// 미방문 노드 (이후 order)
		if (visitOrder[nxt] == 0) {

			if (p == -1) {
				// 자식 수 증가
				rootchild++;
			}

			visitOrder[nxt] = ++vstcnt; // 방문처리, order 기록

			int l = dfs(nxt, cur);

			if (p != -1 && !(cut[cur]) && l >= visitOrder[cur]) {
				cutcnt++;
				cut[cur] = true;
				//cout << "[debug]" << cur << "is cut\n";
			}

			if (low > l) low = l;
		}
		// 기방문 노드 (이전 order)
		else {
			if (low > visitOrder[nxt]) low = visitOrder[nxt];
			// 엄밀한 low는 아니지만 p의 order보단 무조건 작으므로 판별에는 문제가 없다.
		}
	}

	if (rootchild > 1) {
		cutcnt++;
		cut[cur] = true;
		//cout << "[debug]" << cur << "is cut\n";
	}

	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	while (E--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= V && vstcnt < V; i++) {
		if (visitOrder[i] == 0) {
			roots.push_back(i);
			cntcom++;
			//cout << "[debug]" << i << "is root\n";
			visitOrder[i] = ++vstcnt;
			dfs(i, -1);
		}
	}

	cout << cutcnt << "\n";
	for (int i = 1; i <= V; i++) {
		if (cut[i]) cout << i << " ";
	}

	return 0;
}