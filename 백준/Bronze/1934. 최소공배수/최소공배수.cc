#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, A, B;
    cin>>T;

    while(T--){
        cin>>A>>B;
        cout<<(A*B)/gcd(A,B)<<"\n";
    }

    return 0;
}