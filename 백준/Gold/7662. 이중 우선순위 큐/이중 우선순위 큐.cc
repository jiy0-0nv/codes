#include <bits/stdc++.h>
#include <queue>
#include <set>
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--){
        priority_queue<int> maxh = {};
        priority_queue<int, vector<int>, greater<int>> minh = {};
        multiset<int> mset = {};

        int k;
        cin >> k;

        while (k--){
            char E;
            cin >> E;
            int n;
            cin >> n;
            if (E == 'I') {
                maxh.push(n);
                minh.push(n);
                mset.insert(n);
            }
            else if (mset.empty()){
                continue;
            }
            else if (n == 1) {
                while (1){
                    int mx = maxh.top();
                    maxh.pop();
                    auto it = mset.find(mx);
                    if (it == mset.end()) continue;
                    mset.erase(it);
                    break;
                }
            }
            else if (n == -1) {
                while (1){
                    int mn = minh.top();
                    minh.pop();
                    auto it = mset.find(mn);
                    if (it == mset.end()) continue;
                    mset.erase(it);
                    break;
                }
            }
        }

        if (mset.empty()){
            cout << "EMPTY\n";
            continue;
        }

        while (1){
            int mx = maxh.top();
            maxh.pop();
            auto it = mset.find(mx);
            if (it == mset.end()) continue;
            cout << mx << " ";
            break;
        }

        while (1){
            int mn = minh.top();
            minh.pop();
            auto it = mset.find(mn);
            if (it == mset.end()) continue;
            cout << mn << "\n";
            break;
        }
    }

    return 0;
}