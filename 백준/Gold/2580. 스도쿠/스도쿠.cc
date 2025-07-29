#include <bits/stdc++.h>
using namespace std;

int board[9][9] = {0,};
bool rows[9][10];
bool cols[9][10];
bool boxs[9][10];

int empties[81][2];
int ecnt = 0;

int stop = false;

void bt(int coo){
    if (coo==ecnt) {
        stop = true;
        return;
    }

    int r = empties[coo][0];
    int c = empties[coo][1];

    bool nl[10] = {false};;
    for (int i=1;i<10;i++) {
        if (rows[r][i] || cols[c][i] || boxs[(r/3)*3+(c/3)][i]) nl[i] = true;
    }
    for (int i=1;i<10;i++){
        if (!(nl[i])){
            rows[r][i] = true;
            cols[c][i] = true;
            boxs[(r/3)*3+(c/3)][i] = true;
            board[r][c] = i;
            bt(coo+1);
            if (stop) return;
            rows[r][i] = false;
            cols[c][i] = false;
            boxs[(r/3)*3+(c/3)][i] = false;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            int n;
            cin >> n;

            board[i][j] = n;
            rows[i][n] = true;
            cols[j][n] = true;
            boxs[(i/3)*3+(j/3)][n] = true;

            if (n==0){
                empties[ecnt][0] = i;
                empties[ecnt][1] = j;
                ecnt++;
            }
        }
    }

    bt(0);

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}