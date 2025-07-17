#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    bool empty = true;

    for (int i=1; i<6; ++i){
        string name;
        cin >> name;
        if (name.find("FBI") != string::npos){
            cout << i << " ";
            if (empty) empty = false;
        }
    }

    if (empty) cout << "HE GOT AWAY!";

    return 0;
}