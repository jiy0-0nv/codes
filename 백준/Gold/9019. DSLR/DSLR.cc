#include <bits/stdc++.h>
#include <deque>
using namespace std;

int T;

int D(int x) {
    return (x * 2) % 10000;
}

int S(int x) {
    if (x == 0) return 9999;
    else return (x - 1);
}

int L(int x) {
    return (x / 1000 + (x * 10) % 10000);
}

int R(int x) {
    return (x / 10 + (x % 10) * 1000);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        char ops[10000] = {'\0'};
        int nums[10000] = {0};

        int A, B;
        cin >> A >> B;

        deque<int> dq = {A};
        ops[A] = 'A';

        while (!dq.empty()) {
            A = dq.front();
            dq.pop_front();

            //cout << "[DEBUG] " << A << "\n";

            if (A == B) {
                break;
            }

            if (ops[D(A)] == '\0') {
                ops[D(A)] = 'D';
                nums[D(A)] = A;
                dq.push_back(D(A));
            }
            if (ops[S(A)] == '\0') {
                ops[S(A)] = 'S';
                nums[S(A)] = A;
                dq.push_back(S(A));
            }
            if (ops[L(A)] == '\0') {
                ops[L(A)] = 'L';
                nums[L(A)] = A;
                dq.push_back(L(A));
            }
            if (ops[R(A)] == '\0') {
                ops[R(A)] = 'R';
                nums[R(A)] = A;
                dq.push_back(R(A));
            }
        }

        deque<char> ans = {};
        while (ops[A] != 'A') {
            ans.push_back(ops[A]);
            A = nums[A];
        }
        while (!ans.empty()) {
            cout << ans.back();
            ans.pop_back();
        }
        cout << "\n";
    }

    return 0;
}