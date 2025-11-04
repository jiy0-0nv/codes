#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        int ln[3];
        cin >> ln[0] >> ln[1] >> ln[2];
        sort(ln, ln+3);

        cout << "Scenario #" << i << ":\n";
        
        if (ln[0]*ln[0]+ln[1]*ln[1]==ln[2]*ln[2])
            cout << "yes";
        else
            cout << "no";
        
            cout << "\n\n";
    }

    return 0;
}