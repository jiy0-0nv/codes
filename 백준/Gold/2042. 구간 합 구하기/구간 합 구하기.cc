#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int n, m, k;
int sz;
ll arr[1000000];
ll segtree[2097152];

ll maketree(ll node, int s, int e) {
	if (s == e) {
		segtree[node] = arr[s];
		arr[s] = node;
	}
	else {
		int mid = (s + e) / 2;
		segtree[node] = maketree(node * 2, s, mid) + maketree(node * 2 + 1, mid + 1, e);
	}
	return segtree[node];
}

void update(int idx, ll value) {
	int node = arr[idx];
	segtree[node] = value;
	while (node > 1) {
		node /= 2;
		segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
	}
	return;
}

ll trsum(int node, int nodeStart, int nodeEnd, int sumStart, int sumEnd) {
	if (nodeStart >= sumStart && nodeEnd <= sumEnd) return segtree[node];
	else if (nodeStart > sumEnd || nodeEnd < sumStart) return 0;
	else {
		int mid = (nodeStart + nodeEnd) / 2;
		return trsum(node * 2, nodeStart, mid, sumStart, sumEnd) + trsum(node * 2 + 1, mid + 1, nodeEnd, sumStart, sumEnd);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	int h = (int)ceil(log2(n));
	sz = (1 << (h + 1));

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	maketree(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c);
		}
		else {
			cout << trsum(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}
