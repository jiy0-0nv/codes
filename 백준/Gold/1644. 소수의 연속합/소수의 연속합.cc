#if 1
#include <iostream>
#include <math.h>

using namespace std;

int n;
bool notPrime[4000001];
int primeLst[2000000];
int pi = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	int sqrtn = sqrt(n);

	for (int i = 2; i <= sqrtn; i++) {
		if (!(notPrime[i])) {
			primeLst[pi++] = i;
			for (int j = i * 2; j <= n; j += i) {
				notPrime[j] = true;
			}
		}
	}
	for (int i = sqrtn + 1; i <= n; i++) {
		if (!(notPrime[i])) {
			primeLst[pi++] = i;
		}
	}
	
	int s = 0, e = 0;
	int nsum = primeLst[0];
	int ans = 0;

	while (s < pi && e < pi) {
		if (nsum == n) {
			ans++;
			e++;
			if (e < pi) nsum += primeLst[e];
		}
		else if (nsum > n) {
			nsum -= primeLst[s++];
		}
		else {
			e++;
			if (e < pi) nsum += primeLst[e];
		}
	}

	cout << ans;

	return 0;
}
#endif