#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

const int INF = 2e9;

int N;
ll B;
vector<int> a;

bool budgetOk(ll target) {
    ll total = 0;
    
    for (int i = 0; i < N; i++) {
        if (a[i] < target) {
            ll diff = target - a[i];
            
            if (diff * diff > B - total) return false;
            
            total += diff * diff;
        }
    }
    return true;
}

int main() {
    cin >> N >> B;

    a.resize(N);
    ll min_val = INF;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        min_val = min(min_val, (ll)a[i]);
    }

    ll low = min_val;
    ll high = (ll)INF;
    ll ans = low;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (budgetOk(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
