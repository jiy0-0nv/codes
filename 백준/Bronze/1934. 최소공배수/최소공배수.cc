#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, A, B;
    cin>>T;

    for (int i=0; i<T; ++i){
        cin>>A>>B;
        if (A>B) swap(A, B);
        for (int j=1;j<=A;++j){
            if ((B*j)%A==0){
                B *= j;
                break;
            }
        }
        cout<<B<<"\n";
    }

    return 0;
}