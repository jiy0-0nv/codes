#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int first[26] = {};

    while (n--){
        string name;
        cin >> name;

        first[name[0]-'a']++;
    }

    bool PREDAJA = true;
    for (int i=0;i<26;i++){
        if (first[i]>=5){
            cout << (char)('a'+i);
            PREDAJA = false;
        }
    }

    if (PREDAJA) cout << "PREDAJA";

    return 0;
}