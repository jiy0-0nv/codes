#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    int sky[101][101];

    for (int r=0; r<H; r++){
        char row[102];
        cin >> row;
        for (int c=0; c<W; c++){
            if (row[c]=='c'){
                sky[r][c] = 0;
            }
            else
                sky[r][c] = -1;
        }
    }

    for (int r=0; r<H; r++){
        for (int c=0; c<W; c++){
            if (sky[r][c] == 0){
                for (int m=c+1; m<W; m++){
                    if (sky[r][m] == 0) break;
                    sky[r][m] = sky[r][m-1] + 1;
                }
            }
            cout << sky[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}