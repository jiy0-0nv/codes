#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double m;
    cin >> m;
    if (m <= 30)
        printf("%.1f", m / 2);
    else
        printf("%.1f", (m - 30) * 1.5 + 15);

    return 0;
}