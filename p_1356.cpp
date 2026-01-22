#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    ll hash;
    int len;
};

ll B, P;
vector<ll> powB;
vector<Node> seg;

Node mergeNode(const Node &L, const Node &R) {
    if (L.len == 0) return R;
    if (R.len == 0) return L;
    Node res;
    res.len = L.len + R.len;
    res.hash = (L.hash * powB[R.len] + R.hash) % P;
    return res;
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = {0, 1};
        return;
    }
    int mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
}

void update(int idx, int l, int r, int pos, ll val) {
    if (l == r) {
        seg[idx].hash = val % P;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(idx * 2, l, mid, pos, val);
    else
        update(idx * 2 + 1, mid + 1, r, pos, val);

    seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return {0, 0};
    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) / 2;
    return mergeNode(
        query(idx * 2, l, mid, ql, qr),
        query(idx * 2 + 1, mid + 1, r, ql, qr)
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, N;
    while (cin >> B >> P >> L >> N) {
        if (B == 0 && P == 0 && L == 0 && N == 0) break;

        powB.assign(L + 1, 1);
        for (int i = 1; i <= L; i++)
            powB[i] = (powB[i - 1] * B) % P;

        seg.assign(4 * (L + 5), {0, 0});
        build(1, 1, L);

        for (int i = 0; i < N; i++) {
            char type;
            cin >> type;
            if (type == 'E') {
                int pos;
                ll val;
                cin >> pos >> val;
                update(1, 1, L, pos, val);
            } else { // 'H'
                int l, r;
                cin >> l >> r;
                Node res = query(1, 1, L, l, r);
                cout << res.hash << "\n";
            }
        }
        cout << "-\n";
    }
    return 0;
}

