#include <iostream>
using namespace std;

int n, m;
int ans[10];
bool vst[10];

void dfs(int d) {
	if (d == m) {
		for (int i = 0; i < m; i++) cout << ans[i]<<"\n";
	}
	for (int i = 1; i <= n; i++) {
		if (vst[i]) continue;
		ans[d] = i;
		vst[i] = true;
		dfs(d + 1);
		vst[i] = false; 
	}
}

int main()
{

	cin >> n >> m;
	dfs(0);

	return 0;
}