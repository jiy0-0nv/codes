#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    int al[100000];
    for (int i=0; i<n; i++) cin>>al[i];
    sort(al, al+n);

    cin >> m;
    for (int i=0; i<m; i++) {
        int x;
        cin>>x;
        cout << binary_search(al, al+n, x) << "\n";
    }
    return 0;
}