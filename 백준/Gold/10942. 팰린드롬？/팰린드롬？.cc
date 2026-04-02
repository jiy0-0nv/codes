#include<iostream>
using namespace std;

int N, M;
int NUMS[2001];
bool PD[2001][2001];
bool CK[2001][2001];

bool isPD(int s, int e) {
    int len = e - s + 1;
    if (len == 1) return true;
    while (s<e) {
        if (CK[s][e]) return PD[s][e];
        if (NUMS[s]!=NUMS[e]) return false;
        s++;
        e--;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0;i<N;i++) cin >> NUMS[i];

    for (int l=1; l<=N; l++) {
        for (int s=0; s+l-1<=N; s++) {
            PD[s][s+l-1] = isPD(s, s+l-1);
            CK[s][s+l-1] = true;
        }
    }

    cin >> M;
    while (M--) {
        int S, E;
        cin >> S >> E;
        cout << PD[S-1][E-1] << "\n";
    }

    return 0;
}