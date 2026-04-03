#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
vector<ll> NV;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    NV.assign(N, 0);
    for (int i=0; i<N; i++) {
        cin >> NV[i];
    }

    sort(NV.begin(), NV.end());

    ll sum = abs(NV[0] + NV[1] + NV[2]);
    ll ans[3] = {NV[0], NV[1], NV[2]};

    for (int i=0; i<N-2; i++) {
        // 투포인터
        int s = i + 1;
        int e = N - 1;

        while (s < e) {
            ll tsum = NV[i] + NV[s] + NV[e];
            if (tsum == 0) {
                cout << NV[i] << " " << NV[s] << " " << NV[e];
                return 0;
            }

            if (abs(tsum) < sum) {
                sum = abs(tsum);
                ans[0] = NV[i];
                ans[1] = NV[s];
                ans[2] = NV[e];
            }

            if (tsum < 0) {
                s++;
            }
            else if (tsum > 0) {
                e--;
            }
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2];

    return 0;
}