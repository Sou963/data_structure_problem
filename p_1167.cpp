#include <bits/stdc++.h>
using namespace std;

struct Child {
    string name;
    int value;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<Child> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i].name >> v[i].value;
        }

        int cur = 0;
        int step = v[cur].value;

        while (v.size() > 1) {
            int size = v.size();

            if (step % 2 == 1) {
                cur = (cur + step) % size;
            } else {
                cur = (cur - (step % size) + size) % size;
            }

            step = v[cur].value;
            v.erase(v.begin() + cur);

            if (cur == v.size()) cur = 0;
        }

        cout << "Vencedor(a): " << v[0].name << "\n";
    }
    return 0;
}
