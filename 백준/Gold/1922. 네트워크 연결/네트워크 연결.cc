#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int r[1001];

int find(int k) {
	if (!r[k]) return k;
	else return r[k] = find(r[k]);
}

void join(int a, int b) {
	int x = find(a);
	int y = find(b);
	r[y] = x;
}

struct edge_t {
	int a, b, cost;
	inline bool operator<(const edge_t &ref) const {
		return this->cost < ref.cost;
	}
} Edge[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		Edge[i].a = a;
		Edge[i].b = b;
		Edge[i].cost = c;
	}

	sort(Edge, Edge + m);

	int cnt = 0, sum = 0;

	for (int i = 0; i < m && cnt < n - 1; i++) {
		if (find(Edge[i].a) != find(Edge[i].b)){
			join(Edge[i].a, Edge[i].b);
			cnt++;
			sum += Edge[i].cost;
		}
	}

	cout << sum;

	return 0;
}