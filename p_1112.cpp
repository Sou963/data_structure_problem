#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int BIT[MAX][MAX];
int X, Y, P;

void update(int x, int y, int val) {
    for (int i = x; i <= X; i += i & -i) {
        for (int j = y; j <= Y; j += j & -j) {
            BIT[i][j] += val;
        }
    }
}

int query(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            sum += BIT[i][j];
        }
    }
    return sum;
}

int queryRect(int x1, int y1, int x2, int y2) {
    return query(x2, y2)
         - query(x1 - 1, y2)
         - query(x2, y1 - 1)
         + query(x1 - 1, y1 - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> X >> Y >> P;
        if (X == 0 && Y == 0 && P == 0) break;
        memset(BIT, 0, sizeof(BIT));

        int Q;
        cin >> Q;

        while (Q--) {
            char type;
            cin >> type;

            if (type == 'A') {
                int n, a, b;
                cin >> n >> a >> b;
                update(a + 1, b + 1, n);
            }
            else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                int lx = min(x1, x2) + 1;
                int rx = max(x1, x2) + 1;
                int ly = min(y1, y2) + 1;
                int ry = max(y1, y2) + 1;

                int total = queryRect(lx, ly, rx, ry);
                cout << total * P << "\n";
            }
        }

        cout << "\n";
    }

    return 0;
}

