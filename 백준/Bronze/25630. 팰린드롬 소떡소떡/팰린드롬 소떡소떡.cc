#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    char s[101]; cin >> s;
    int ans = 0;

    for (int i = 0; i < N / 2; i++){
        if (s[i] != s[N - 1 - i]) ans++;
    }
    cout << ans;

    return 0;
}