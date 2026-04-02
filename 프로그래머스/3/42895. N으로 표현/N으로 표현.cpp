#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> counts;
bool vst[32001];

int newnum(int c) {
    int res = 0;
    for (int i=0; i<c; i++) {
        res += pow(10, i);
    }
    return res;
}

int solution(int N, int number) {
    int ans;
    
    counts.assign(9, {});
    fill(vst, vst+32001, false);
    
    for (ans=1; ans<=8; ans++) {
        int nn = newnum(ans) * N;
        if (nn == number) return ans;
        if (nn >= 1 && nn <= 32000 && !vst[nn]) counts[ans].push_back(nn);
        
        for (int i=1; i<ans; i++) {
            for (int a : counts[i]) {
                for (int b : counts[ans-i]) {
                    int c;
                    
                    c = a + b;
                    if (c == number) return ans;
                    if (c >= 1 && c <= 32000 && !vst[c])
                        counts[ans].push_back(c);
                    
                    c = a - b;
                    if (c == number) return ans;
                    if (c >= 1 && c <= 32000 && !vst[c])
                        counts[ans].push_back(c);
                    
                    c = a * b;
                    if (c == number) return ans;
                    if (c >= 1 && c <= 32000 && !vst[c])
                        counts[ans].push_back(c);
                    
                    c = a / b;
                    if (c == number) return ans;
                    if (c >= 1 && c <= 32000 && !vst[c])
                        counts[ans].push_back(c);
                }
            }
        }
    }
    
    return -1;
}