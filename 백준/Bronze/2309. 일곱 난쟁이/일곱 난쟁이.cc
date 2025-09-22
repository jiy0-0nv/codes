#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int nums[10];
int sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i=0; i<9; i++){
        cin >> nums[i];
        sum += nums[i];
    }

    sort(nums, nums+9);

    int a, b;
    for (int i=0; i<8; i++){
        int t = sum - 100 - nums[i];
        auto it = std::find(nums + i + 1, nums + 9, t);
        if (it != nums + 9){
            a = nums[i];
            b = *it;
        }
    }

    for (int i=0; i<9; i++){
        int n = nums[i];
        if (n != a && n != b){
            cout << n << "\n";
        }
    }

    return 0;
}