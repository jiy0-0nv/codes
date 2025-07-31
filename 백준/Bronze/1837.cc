#if 1
#include <iostream>
#define ll long long

using namespace std;

int mod(char* arr, int m){

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char pwd[101];
	cin >> pwd;
	
	ll k;
	cin >> k;

	int ans = mod(pwd, k);
	if (ans == -1) cout << "GOOD";
	else cout << "BAD " << ans;

	return 0;
}
#endif
