#include <string>
#include <vector>

using namespace std;

int countOne(string x) {
    int a = 0;
    for (int i=0; i<=x.length(); i++)
        if (x[i] == '1') a++;
    return a;
}

pair<int, int> toBin(int x) {
    int zero = 0;
    int one = 0;
    while (x > 1) {
        if (x % 2) one++;
        else zero++;
        x /= 2;
    }
    if (x == 1) one++;
    else zero++;
    return {zero, one};
}

vector<int> solution(string s) {
    vector<int> answer = {0, 0};
    
    int one = countOne(s);
    int zero = s.length() - one;
    
    while (1) {
        if (one == 1 && zero == 0)
            break;
        // 0 제거
        answer[1] += zero;
        // 길이->2진수
        pair<int, int> p = toBin(one);
        zero = p.first;
        one = p.second;
        
        answer[0]++;
    }
    
    return answer;
}