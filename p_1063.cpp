#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<char> in(n), out(n);

        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> out[i];

        stack<char> st;
        string ops = "";
        int j = 0;

        // Simulate
        for (int i = 0; i < n; i++) {
            st.push(in[i]);
            ops += 'I';

            while (!st.empty() && j < n && st.top() == out[j]) {
                st.pop();
                ops += 'R';
                j++;
            }
        }
        if (j == n) {
            cout << ops << "\n";
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}
