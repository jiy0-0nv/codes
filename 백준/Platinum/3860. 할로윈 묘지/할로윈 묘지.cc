#if 01
#include <iostream>
#include <vector>
#include <queue>
#define INF 400000000

using namespace std;

int W, H, G, E;

struct node {
	int x; // -2: 묘비 / -1: 잔디 / 양수: 귀신구멍 출구 x좌표
	int y; // 귀신구멍 출구 y좌표
	int t; // 귀신구멍 시간
};

node graph[30][30];
int vst[30][30];

int DIR[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> W >> H;
		if (W == 0) return 0;

		//cout << "[debug] H, W is" << H << W << "\n";

		// init
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				graph[i][j].x = -1;
				vst[i][j] = INF;
			}
		}

		cin >> G;

		while (G--) {
			int x, y;
			cin >> x >> y;
			graph[y][x].x = -2; // 묘지
		}
		
		//cout << "[debug] graves saved\n";
		
		cin >> E;

		while (E--) {
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			graph[y1][x1].x = x2;
			graph[y1][x1].y = y2;
			graph[y1][x1].t = t;
		}

		//cout << "[debug] holes saved\n";
		//cout << "[debug] start loop\n";

		// 벨만포드
		vst[0][0] = 0; // 출발점
		for (int i = 0; i < H * W - 1; i++) {
			for (int r = 0; r < H; r++) {
				for (int c = 0; c < W; c++) {
					if (r == H - 1 && c == W - 1) continue; // 도착점
					if (vst[r][c] == INF) continue; // 아직 도달 안함
					
					if (graph[r][c].x == -1) { // 잔디
						for (auto& dir : DIR) {
							int x = c + dir[0];
							int y = r + dir[1];
							if (y >= 0 && y < H && x >= 0 && x < W) {
								if (vst[y][x] > vst[r][c] + 1) vst[y][x] = vst[r][c] + 1;
							}
						}
					}
					else if (graph[r][c].x >= 0) { // 귀신구멍
						int x = graph[r][c].x;
						int y = graph[r][c].y;
						if (vst[y][x] > vst[r][c] + graph[r][c].t) vst[y][x] = vst[r][c] + graph[r][c].t;
					}
					// else if (graph[r][c].x == -2) 묘비는 갈 수 없음
				}
			}

			/*cout << "[debug]\n";
			for (int r = 0; r < H; r++) {
				for (int c = 0; c < W; c++) {
					cout << vst[r][c] << " ";
				}
				cout << "\n";
			}*/
		}

		

		bool never = false;
		// 음수 사이클 판별을 위해 한번 더 돌려줌
		for (int r = 0; r < H; r++) {
			for (int c = 0; c < W; c++) {
				if (r == H - 1 && c == W - 1) continue; // 도착점
				if (vst[r][c] == INF) continue; // 아직 도달 안함

				if (graph[r][c].x == -1) { // 잔디
					for (auto& dir : DIR) {
						int x = c + dir[0];
						int y = r + dir[1];
						if (y >= 0 && y < H && x >= 0 && x < W) {
							if (vst[y][x] > vst[r][c] + 1) {
								never = true;
								break;
							}
						}
					}
				}
				else if (graph[r][c].x >= 0) { // 귀신구멍
					int x = graph[r][c].x;
					int y = graph[r][c].y;
					if (vst[y][x] > vst[r][c] + graph[r][c].t) {
						never = true;
						break;
					}
				}
			}
		}

		// 이후 결과 출력!
		if (never) cout << "Never\n";
		else if (vst[H - 1][W - 1] == INF) cout << "Impossible\n";
		else cout << vst[H - 1][W - 1] << "\n";
	}
	return 0;
}
#endif