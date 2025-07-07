#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    int a[1000];

    int t=n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if (a[i]==a[0]+k*i) t--;
    }
    if (t==0){
        cout<<t;
        return 0;
    }
    
    for(int b=1;b<n;++b){
        if(a[b]-k*b<1) continue;
        int bt = n-1;
        for(int i=0;i<n;++i){
            if(i<b && a[b]==a[i]+k*(b-i)) bt--;
            else if(i>b && a[i]==a[b]+k*(i-b)) bt--;
        }
        if (bt<t) t=bt;
    }
    cout<<t;
    return 0;
}