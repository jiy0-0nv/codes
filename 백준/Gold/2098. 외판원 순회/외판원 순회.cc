#if 01
#include <iostream>
#include <algorithm>
#include <cstring> // memset
#define INF 987654321

using namespace std;

int N; // 정점 번호
int W[16][16]; // 인접 행렬
int  D[16][1 << 16]; // D[i][j] - i번 정점에 위치, 방문 히스토리가 j일 때 최소비용
int fullvst;

int tsp(int cur, int visited) {
	// 전부 방문한 경우
	if (visited == fullvst) {
		return W[cur][0] == 0 ? INF : W[cur][0];
	}
	int &t = D[cur][visited];
	// 이미 코스트를 구한 경우
	if (t != -1) return t;
	t = INF;
	// i번째 bit를 비우며 재귀 탐색
	for (int i = 0; i < N; i++) {
		// [skip 조건]
		// visited & (1 << i) : 방문한 곳 중 겹치는 게 있음
		// D[cur][i] == 0 : cur에서 i로 가는 길이 없음
		if ((visited & (1 << i)) || (W[cur][i] == 0)) continue;
		t = min(t, tsp(i, visited | (1 << i)) + W[cur][i]);
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	// init
	fullvst = (1 << N) - 1;
	memset(D, -1, sizeof(D));

	cout << tsp(0, 1);

	return 0;
}
#endif