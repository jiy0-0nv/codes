#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int m = 0;
    int idx = -1;

    for (int i=0; i<13; i++){
        if (s[i] == '*') idx = i;
        else if (i % 2 == 0) m += s[i] - '0';
        else m += (s[i] - '0') * 3;
    }

    m %= 10;
    if (idx % 2 == 0) cout << (10 - m) % 10;
    else {
        for (int i=0; i<10; i++){
            if ((m + 3 * i) % 10 == 0){
                cout << i;
                break;
            }
        }
    }

    return 0;
}