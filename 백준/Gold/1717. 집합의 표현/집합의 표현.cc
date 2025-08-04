#include <iostream>

using namespace std;

int n, m;
int r[1000001];

int find(int k) {
	if (r[k] == k) return k;
	else return r[k] = find(r[k]);
}

void group(int a, int b) {
	int x = find(a);
	int y = find(b);
	r[y] = x;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		r[i] = i;
	}

	int t, a, b;

	while (m--) {
		cin >> t >> a >> b;

		if (t == 0) {
			group(a, b);
		}
		else {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}