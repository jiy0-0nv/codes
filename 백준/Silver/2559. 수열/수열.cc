#include <bits/stdc++.h>
using namespace std;

int prefix[100001] = {0,};
int ans = -10000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int i=1; i<=N; i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];

        if (i<K) continue;
        int partial = prefix[i]-prefix[i-K];
        if (ans < partial) ans = partial;
    }

    cout << ans;

    return 0;
}