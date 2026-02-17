#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    const int SL = S.length();
    int idx = 0;

    string B;
    cin >> B;
    const int BL = B.length();

    deque<char> st;

    while (idx < SL) {
        char c = S[idx];
        st.push_back(c);
        int bidx = BL - 1;
        if (c == B[bidx]) {
            deque<char> temp;
            while (bidx >= 0) {
                if (!st.empty() && st.back() == B[bidx]){
                    char tc = st.back();
                    st.pop_back();
                    if (bidx == 0) {
                        break;
                    }
                    temp.push_back(tc);
                    bidx--;
                }
                else {
                    while (!temp.empty()) {
                        char tc = temp.back();
                        temp.pop_back();
                        st.push_back(tc);
                    }
                    break;
                }
            }
        }
        idx++;
    }

    if (st.empty()) {
        cout << "FRULA";
    }
    else {
        while (!st.empty()) {
            cout << st.front();
            st.pop_front();
        }
    }

    return 0;
}