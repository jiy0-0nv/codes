#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int nums[10];
bool np[10000000];

bool canMake(int num) {
    int n = num;
    
    int ns[10];
    for (int i=0; i<10; i++)
        ns[i] = nums[i];
    
    while (n) {
        int t = n % 10;
        if (ns[t]) {
            ns[t]--;
            n /= 10;
        }
        else {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    fill(nums, nums+10, 0);
    for (char n : numbers)
        nums[n - '0']++;
    
    fill(np, np+10000000, false);
    for (int i=2; i<5000000; i++) {
        if (!np[i]) {
            if (canMake(i)) answer++;
            for (int j=i; j<10000000; j+=i) {
                np[j] = true;
            }
        }
    }
    for (int i=5000000; i<10000000; i++)
        if (!np[i] && canMake(i)) answer++;
    
    return answer;
}
