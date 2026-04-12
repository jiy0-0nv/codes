#include<iostream>
#include <algorithm>
using namespace std;

int N;
int S[21][21];
bool vst[21];
int min_diff = 100000; // 100*20*20 이상

void bt(int pl, int num) {
    if (num == N/2) {
        int team1 = 0;
        int team2 = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (vst[i] && vst[j]) team1 += S[i][j];
                if (!vst[i] && !vst[j]) team2 += S[i][j];
            }
        }
        int diff = abs(team1-team2);
        min_diff = min(min_diff, diff);
        return;
    }

    for (int i=pl+1; i<N; i++) {
        if (!vst[i]) {
            vst[i] = true;
            bt(i, num+1);
            vst[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> S[i][j];
        }
    }

    fill(vst, vst+N, false);
    vst[0] = true;
    bt(0, 1);

    cout << min_diff << "\n";

    return 0;
}