#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    int c1 = (n < 6) ? 6 - n : 0 ;
    int c2 = 1;
    int c3 = 1;
    int c4 = 1;
    int c5 = 1;
    std::string specials = "!@#$%^&*()-+";

    for (int i=0; i<n; ++i){
        char c;
        cin>>c;
        int cint;
        cint = (int)c;

        if (c2&&cint>='0'&&cint<='9') c2 = 0;
        if (c3&&cint>='a'&&cint<='z') c3 = 0;
        if (c4&&cint>='A'&&cint<='Z') c4 = 0;
        if (c5&&specials.find(c)!=std::string::npos) c5 = 0;
    }

    int ans = (c1 > c2 + c3 + c4 + c5) ? c1 : c2 + c3 + c4 + c5;
    cout<<ans<<"\n";

    return 0;
}