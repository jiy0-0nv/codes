#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<int> dq;
    string cmd;

    while(n--){
        cin >> cmd;
        if (cmd == "push"){
            int x;
            cin >> x;
            dq.push_back(x);
        } else if (cmd == "pop"){
            if (dq.empty()) cout<<-1<<"\n";
            else{
                cout<<dq.front()<<"\n";
                dq.pop_front();
            }
        } else if (cmd =="size"){
            cout<<dq.size()<<"\n";
        } else if (cmd =="empty"){
            if (dq.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";
        } else if (cmd =="front"){
            if (dq.empty()) cout<<-1<<"\n";
            else cout<<dq.front()<<"\n";
        } else if (cmd =="back"){
            if (dq.empty()) cout<<-1<<"\n";
            else cout<<dq.back()<<"\n";
        }
    }
    return 0;
}