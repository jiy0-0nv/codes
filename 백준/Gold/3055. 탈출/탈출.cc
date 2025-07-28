#if 1
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int r, c;
int map[50][50];
bool vst[50][50];

struct Node {
	int row, col, type, time;
};

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;

	queue<Node> q = {};

	int sr, sc;
	
	char t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> t;
			if (t == '.') map[i][j] = 0;
			else if (t == '*') {
				map[i][j] = 1;
				q.push({ i, j, 1, 0 });
			}
			else if (t == 'X') map[i][j] = 2;
			else if (t == 'D') map[i][j] = 3;
			else if (t == 'S') {
				map[i][j] = 0;
				sr = i; sc = j;
			}
		}
	}

	q.push({ sr, sc, 0, 0 });
	vst[sr][sc] = true;

	while (!(q.empty())) {
		Node n = q.front();
		q.pop();
		int nt = n.type;

		for (int* d : dir) {
			int nr, nc;
			nr = n.row + d[0];
			nc = n.col + d[1];

			if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
			if (nt == 0 && vst[nr][nc]) continue;

			if (nt == 0 && map[nr][nc] == 3) {
				cout << n.time + 1;
				return 0;
			}
			else if (map[nr][nc] == 0) {
				q.push({ nr, nc, nt, n.time + 1 });
				if (nt == 1) map[nr][nc] = 1;
				if (nt == 0) vst[nr][nc] = true;
			}
		}

	}

	cout << "KAKTUS";
	return 0;
}
#endif