#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n, m;

vector<int> graph[100001];
int parent[18][100001];
int d[100001];

int lca(int a, int b) {
	// a와 b의 depth 맞춰주기
	if (d[a] > d[b]) swap(a, b); // a가 더 높은 곳에 위치
	// b를 올려줌
	int dst = d[b] - d[a];
	int i = 0;
	int mask = 1;
	while (dst > 0) {
		if (dst & mask) {
			b = parent[i][b];
			dst -= mask;
		}
		mask <<= 1;
		i++;
	}

	// 동시에 올라가며 만나는 곳 찾기
	// 여기 다시해보기...
 	while (a != b) {
		int j;
		for (j = 0; j < 18; j++) {
			if (parent[j][a] == parent[j][b]) break;
		}
		if (j > 0) --j;
		a = parent[j][a];
		b = parent[j][b];
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// bfs
	bool vst[100001] = {};
	deque<int> q = { 1 };
	vst[1] = true;
	int td = 0;
	d[1] = 0;
	while (!q.empty()) {
		int t = q.front();
		q.pop_front();
		for (int s : graph[t]) {
			if (!vst[s]) {
				q.push_back(s);
				vst[s] = true;
				parent[0][s] = t;
				d[s] = d[t] + 1;
			}
		}
	}

	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

	return 0;
}