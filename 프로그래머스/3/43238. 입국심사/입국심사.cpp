#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll solution(int n, vector<int> times) {
    ll answer = 0;
    
    ll s = 1;
    ll e = (ll)*max_element(times.begin(), times.end()) * n;
    
    while (s <= e) {
        ll mid = s + (e - s) / 2;
        ll cnt = 0; // 심사한 사람 수
        
        for (int time : times) {
            cnt += mid / time;
            if (cnt >= n) break;
        }
        
        if (cnt < n) {
            s = mid + 1;
        }
        else if (cnt >= n) {
            e = mid - 1;
            answer = mid;
        }
    }
    
    return answer;
}