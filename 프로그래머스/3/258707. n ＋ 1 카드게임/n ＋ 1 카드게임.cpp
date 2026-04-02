#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    
    int n = cards.size();
    
    vector<int> vst_r(n+1, -1);
    priority_queue<int, vector<int>, greater<int>> minh;
    
    // 초기 카드 처리
    for (int i=0; i<n/3; i++) {
        int card = cards[i];
        vst_r[card] = 0;
        if (vst_r[n+1-card]!=-1) minh.push(0); 
    }
    
    // 라운드 시작
    int round;
    for (round=1; round<=n/3+1; round++) {
        // 카드 없으면 종료
        if (round==n/3+1) break;
        
        // 새로 들어온 카드 처리
        int c1 = cards[n/3 + 2*(round-1)];
        vst_r[c1] = round;
        if (vst_r[n+1-c1]!=-1) {
            int cost = (vst_r[n+1-c1]==0) ? 1 : 2;
            minh.push(cost);
        }
        
        int c2 = cards[n/3 + 2*(round-1) + 1];
        vst_r[c2] = round;
        if (vst_r[n+1-c2]!=-1) {
            int cost = (vst_r[n+1-c2]==0) ? 1 : 2;
            minh.push(cost);
        }
        
        // 다음 라운드 진행 가능한지 확인
        if (minh.empty() || minh.top() > coin) break;
        else {
            coin -= minh.top();
            minh.pop();
        }
    }
    
    return round;
}