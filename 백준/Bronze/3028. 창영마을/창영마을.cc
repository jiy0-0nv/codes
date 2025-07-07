#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 1;
    char move[50];

    cin>>move;
    for (int i=0; i<50; ++i){
        char t = move[i];
        if (t=='\0') break;

        if (t=='A'){
            if (ans==1) ans=2;
            else if (ans==2) ans=1;
        }
        else if (t=='B'){
            if (ans==2) ans=3;
            else if (ans==3) ans=2;
        }
        else if (t=='C'){
            if (ans==1) ans=3;
            else if (ans==3) ans=1;
        }
    }
    cout<<ans;

    return 0;
}
