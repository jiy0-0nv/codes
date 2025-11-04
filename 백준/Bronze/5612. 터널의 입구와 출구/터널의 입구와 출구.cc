#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int maxcar = m;

    while (n--) {
        int ic, oc;
        cin >> ic >> oc;

        m = m + ic - oc;

        if (m < 0){
            cout << 0;
            return 0;
        }
        else if (m > maxcar){
            maxcar = m;
        }
    }

    cout << maxcar;
    return 0;
}