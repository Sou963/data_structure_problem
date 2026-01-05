#include <bits/stdc++.h>
using namespace std;

bool isPair(char a, char b) {
    return (a == 'B' && b == 'S') ||
           (a == 'S' && b == 'B') ||
           (a == 'C' && b == 'F') ||
           (a == 'F' && b == 'C');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s) {
        stack<char> st;
        int ans = 0;

        for (char c : s) {
            if (!st.empty() && isPair(st.top(), c)) {
                st.pop();
                ans++;
            } else {
                st.push(c);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

