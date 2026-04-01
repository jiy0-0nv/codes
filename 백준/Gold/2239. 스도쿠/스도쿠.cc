#include<iostream>
using namespace std;

int board[9][9];

bool check(int r, int c, int n) {
    for (int i=0; i<9; i++) {
        if (board[r][i] == n) return false;
        if (board[i][c] == n) return false;
    }

    // 3x3 검사
    int rs = (r/3) * 3;
    int cs = (c/3) * 3;
    for (int ri=rs;ri<=rs+2;ri++){
        for (int ci=cs;ci<=cs+2;ci++){
            if (board[ri][ci] == n) return false;
        }
    }
    return true;
}

bool bt(int r, int c) {
    if (r==9) return true; // 끝까지 도달

    // 다음 칸 좌표 계산
    int nr = (c == 8) ? r + 1 : r;
    int nc = (c == 8) ? 0 : c + 1;

    // 이미 숫자가 채워진 경우
    if (board[r][c] != 0) return bt(nr, nc);

    // 빈 칸인 경우
    for (int i=1; i<=9; i++) {
        if (check(r, c, i)) {
            board[r][c] = i;
            if (bt(nr, nc)) return true; // 다음 단계가 성공하면 즉시 종료
            else board[r][c] = 0; // 실패 시 상태 복구 (중요!!!!)
        }
    }
    
    // 1~9가 모두 불가능 > 백트래킹 발생
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int r=0;r<9;r++){
        for (int c=0;c<9;c++){
            char n;
            cin >> n;
            board[r][c] = n - '0';
        }
    }

    bt(0, 0);

    for (int r=0;r<9;r++){
        for (int c=0;c<9;c++){
            cout << board[r][c];
        }
        cout << "\n";
    }

    return 0;
}