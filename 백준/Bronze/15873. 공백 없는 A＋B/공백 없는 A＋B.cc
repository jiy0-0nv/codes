#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    char AB[5]; cin >> AB;

    if (AB[1] == '0') {
        A = 10;
        if (AB[3] == '0') B = 10;
        else B = AB[2] - '0';
    }
    else {
        A = AB[0] - '0';
        if (AB[2] == '0') B = 10;
        else B = AB[1] - '0';
    }
    
    cout << A + B;

    return 0;
}