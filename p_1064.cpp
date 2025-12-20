#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (getline(cin, s)) {
        stack<char> st;
        bool ok = true;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                if (st.empty()) {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }

        if (ok && st.empty())
            cout << "correct\n";
        else
            cout << "incorrect\n";
    }

    return 0;
}

