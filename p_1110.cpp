#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        queue<int> q;
        for (int i = 1; i <= n; i++) q.push(i);

        vector<int> discarded;

        while (q.size() > 1) {
            discarded.push_back(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }

        cout << "Discarded cards:";
        if (!discarded.empty()) {
            cout << " ";
            for (int i = 0; i < (int)discarded.size(); i++) {
                cout << discarded[i];
                if (i != discarded.size() - 1) cout << ", ";
            }
        }
        cout << "\n";

        cout << "Remaining card: " << q.front() << "\n";
    }

    return 0;
}

