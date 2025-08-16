#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    int B[1001] = {};
    int ans = 0;
    for (int i=0; i<N; i++){
        int b;
        cin >> b;
        if (ans < ++B[b]) ans = B[b];
    }

    cout << ans;

    return 0;
}