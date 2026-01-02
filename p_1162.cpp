#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int L;
        cin >> L;
        vector<int> v(L);
        for (int i = 0; i < L; i++)
            cin >> v[i];
        int swaps = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L - 1; j++) {
                if (v[j] > v[j + 1]) {
                    swap(v[j], v[j + 1]);
                    swaps++;
                }
            }
        }
        cout << "Optimal train swapping takes " << swaps << " swaps.\n";
    }

    return 0;
}

