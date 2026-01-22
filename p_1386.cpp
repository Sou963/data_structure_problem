#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        vector<bool> visited(N + 1, false);
        int swaps = 0;

        for (int i = 1; i <= N; i++) {
            if (visited[i] || a[i] == i)
                continue;

            int cycle_len = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = a[j];
                cycle_len++;
            }

            if (cycle_len > 0)
                swaps += cycle_len - 1;
        }

        cout << swaps << "\n";
    }

    return 0;
}

