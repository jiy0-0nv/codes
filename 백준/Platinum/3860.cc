#if 01
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int W, H, G, E;

struct Hole {
	int dx;
	int dy;
	int time;
};

int DIR[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (0) {
		cin >> W >> H;
		if (W == 0) return 0;
		cin >> G >> E;

		int graph[30][30];

		while (G--) {
			int x, y;
			cin >> x >> y;
			graph[x][y] = 1; // 묘지
		}
		
		Hole holes[30][30][3];

		while (E--) {
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			holes[x1][y1]->dx = x2;
			holes[x1][y1]->dy = y2;
			holes[x1][y1]->time = t;
		}

		for (int i = 0; i < H * W - 1; i++) {
			for (int r = 0; r < H; r++) {
				for (int c = 0; c < W; c++) {
					for (auto &dir : DIR) {
						
					}
				}
			 }
		}
	}
	return 0;
}
#endif
