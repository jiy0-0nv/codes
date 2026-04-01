#include <bits/stdc++.h>
using namespace std;

int K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    int n = 1;

    while (K > pow(2, n)) {
        K -= pow(2, n);
        n++;
    }

    string ans = "";
    K--;

    for (int i=0; i<n; i++) {
        if (K % 2) {
            ans = '7' + ans;
        }
        else {
            ans = '4' + ans;
        }
        K /= 2;
    }

    cout << ans;
    
    return 0;
}