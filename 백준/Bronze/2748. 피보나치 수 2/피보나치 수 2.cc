#include <bits/stdc++.h>
using namespace std;

int n;
long long fib[3] = {0, 1, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i=3; i<=n; i++){
        fib[i%3] = fib[(i-1)%3] + fib[(i-2)%3];
    }
    cout << fib[n%3];

    return 0;
}