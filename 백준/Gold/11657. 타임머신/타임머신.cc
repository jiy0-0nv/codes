#if 01
#include <iostream>
#define INF 30000000000

using namespace std;

int N, M;
int bus[6001][3];
long dst[6001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 2; i <= N; i++) dst[i] = INF;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus[i][0] = a;
		bus[i][1] = b;
		bus[i][2] = c;
	}

	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < M; i++) {
			int s = bus[i][0];
			int e = bus[i][1];
			int t = bus[i][2];

			if (dst[s] != INF && dst[e] > dst[s] + t) dst[e] = dst[s] + t;
		}
	}

	for (int i = 0; i < M; i++) {
		int s = bus[i][0];
		int e = bus[i][1];
		int t = bus[i][2];

		if (dst[s] != INF && dst[e] > dst[s] + t) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (dst[i]==INF)
			cout << "-1\n";
		else
			cout << dst[i] << "\n";
	}

	return 0;
}
#endif