#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

ll seg[4 * MAXN];
ll lazy[4 * MAXN];

void push(int node, int l, int r) {
    if (lazy[node] != 0) {
        seg[node] += (r - l + 1) * lazy[node];

        if (l != r) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr, ll val) {
    push(node, l, r);

    if (r < ql || l > qr)
        return;

    if (ql <= l && r <= qr) {
        lazy[node] += val;
        push(node, l, r);
        return;
    }

    int mid = (l + r) / 2;

    update(node*2, l, mid, ql, qr, val);
    update(node*2+1, mid+1, r, ql, qr, val);

    seg[node] = seg[node*2] + seg[node*2+1];
}

ll query(int node, int l, int r, int ql, int qr) {
    push(node, l, r);

    if (r < ql || l > qr)
        return 0;

    if (ql <= l && r <= qr)
        return seg[node];

    int mid = (l + r) / 2;

    return query(node*2, l, mid, ql, qr) +
           query(node*2+1, mid+1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, C;
        cin >> N >> C;

        // reset arrays
        memset(seg, 0, sizeof(seg));
        memset(lazy, 0, sizeof(lazy));

        while (C--) {
            int type;
            cin >> type;

            if (type == 0) {
                int p, q;
                ll v;
                cin >> p >> q >> v;
                update(1, 1, N, p, q, v);
            }
            else {
                int p, q;
                cin >> p >> q;
                cout << query(1, 1, N, p, q) << "\n";
            }
        }
    }

    return 0;
}

