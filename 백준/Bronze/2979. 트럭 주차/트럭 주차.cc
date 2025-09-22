#include <bits/stdc++.h>
using namespace std;

int c[4];
int t[101] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i=1;i<=3;i++) cin >> c[i];
    for (int i=0;i<3;i++){
        int arrive, leave;
        cin >> arrive >> leave;

        for (int i=arrive; i<leave; i++){
            t[i]++;
        }
    }

    int ans = 0;
    for (int n : t){
        ans += c[n] * n;
    }

    cout << ans;

    return 0;
}