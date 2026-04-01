#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& roots, int a) {
    // a의 root 찾기
    int root = a;
    if (roots[a] == a) return a;
    return roots[a] = find(roots, roots[a]);
}

void merge(vector<int>& roots, int a, int b) {
    // b를 a에 합침
    int ra = find(roots, a);
    int rb = find(roots, b);
    if (ra != rb) roots[ra] = rb;
}

int solution(vector<int> cards) {    
    int n = cards.size();
    
    vector<int> roots(n+1);
    for (int i=1; i<=n; i++) roots[i] = i;
    
    for (int b=0; b<n; b++) {
        int c = cards[b];
        merge(roots, b+1, c);
    }
    
    vector<int> scores(n+1, 0);
    
    for (int i=1; i<=n; i++) {
        int root = find(roots, roots[i]);
        scores[root]++;
    }
    sort(scores.begin(), scores.end());
    
    int answer = scores[n] * scores[n-1];
    
    return answer;
}