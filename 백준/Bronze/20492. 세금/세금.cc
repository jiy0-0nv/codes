#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double N;
    cin >> N;

    cout << (int)(N * 0.78) << " " << (int)(N * 0.8 + N * 0.2 * 0.78);

    return 0;
}