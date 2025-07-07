#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed;
    cout.precision(2);

    int N, A, T, M, P;
    double S, R;
    double score=0;
    cin>>N;
    while(N--){
        cin>>S>>A>>T>>M;
        score+=(S*(1.0+1.0/A)*(1.0+(M*1.0)/T))/4;
    }
    cin>>P;
    int rank=1;
    for(int i=0;i<P;++i){
        cin>>R;
        if (score<R) rank++;
    }
    string god = (rank>(P+1)*0.15)?" ":" \"The God\" ";
    cout<<"The total score of Younghoon"<<god<<"is "<<score<<".\n";

    return 0;
}