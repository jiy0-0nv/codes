#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, ans;
    cin>>n>>m;
    ans = n;
    
    unordered_map<string, bool> dict;
    for(int i=0;i<n;++i){
        string k;
        cin>>k;
        dict[k] = true;
    }

    while(m--){
        string post;
        cin>>post;
        
        stringstream ss(post);
        string kw;
        while (getline(ss, kw, ',')){
            auto it = dict.find(kw);
            if (it != dict.end() && it->second){
                it->second = false;
                ans--;
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}