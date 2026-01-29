#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N, M;
        cin >> N >> M;
        if (!cin || (N == 0 && M == 0)) break;

        vector<long long> X(M + 2, 0);
        for (int i = 1; i <= M; i++) cin >> X[i];

        // need[i] = how many elements move exactly i positions
        vector<long long> need(M + 1, 0);
        for (int i = 1; i <= M; i++)
            need[i] = X[i] - X[i + 1];

        vector<int> result;
        int cur = N;

        // Build permutation (largest lexicographic)
        for (int shift = M; shift >= 1; shift--) {
            while (need[shift]--) {
                result.push_back(cur);
                cur--;
            }
        }

        // Remaining elements (shift = 0)
        while (cur > 0) {
            result.push_back(cur);
            cur--;
        }

        // Reverse to get correct order
        reverse(result.begin(), result.end());

        // Output
        for (int i = 0; i < N; i++) {
            if (i) cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }
    return 0;
}
