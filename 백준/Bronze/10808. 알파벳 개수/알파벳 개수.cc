#include <bits/stdc++.h>
using namespace std;

string S;
int cnt[26] = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    for (int i=0; i<S.size(); i++)
        cnt[S[i]-'a']++;
    
    for (int i=0; i<26; i++)
        cout << cnt[i] << " ";

    return 0;
}