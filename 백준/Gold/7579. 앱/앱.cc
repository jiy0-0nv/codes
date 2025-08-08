#include <iostream>

using namespace std;

int N, M;
int memory[101]; // i번째 앱의 메모리 사용량
int cost[101]; // i번째 앱의 비활성화 비용

int dp[10001]; // 비용 i로 확보 가능한 최대 메모리

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> memory[i];
	
	for (int i = 0; i < N; i++)
		cin >> cost[i];

	for (int a = 0; a < N; a++) { // 각 앱을 순회
		for (int j = 100 * N; j >= cost[a]; j--) { // 비용을 역순으로 순회 (중복 사용 방지)
			if (dp[j] < dp[j - cost[a]] + memory[a])
				dp[j] = dp[j - cost[a]] + memory[a];
		}
	}

	// M바이트 이상을 확보하는 최소 비용을 찾으면 됨
	for (int i = 0; i <= 10000; i++) {
		if (dp[i] >= M) {
			cout << i;
			break;
		}
	}

	return 0;
}