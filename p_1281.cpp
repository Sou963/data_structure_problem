#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T; // number of test cases

    while (T--) {
        int M;
        cin >> M;

        map<string, double> price;
        for (int i = 0; i < M; i++) {
            string name;
            double p;
            cin >> name >> p;
            price[name] = p;
        }

        int P;
        cin >> P;

        double total = 0.0;
        for (int i = 0; i < P; i++) {
            string item;
            int qty;
            cin >> item >> qty;
            total += price[item] * qty;
        }

        cout << fixed << setprecision(2);
        cout << "R$ " << total << "\n";
    }

    return 0;
}

