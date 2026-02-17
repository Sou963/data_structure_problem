#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct Node {
    int cnt[3];
};

Node seg[4 * MAXN];
int lazy[4 * MAXN];
int N, M;

void build(int node, int l, int r) {
    lazy[node] = 0;
    if (l == r) {
        seg[node].cnt[0] = 1; // initially all are Man
        seg[node].cnt[1] = 0;
        seg[node].cnt[2] = 0;
        return;
    }

    int mid = (l + r) / 2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);

    for (int i = 0; i < 3; i++)
        seg[node].cnt[i] = seg[node*2].cnt[i] + seg[node*2+1].cnt[i];
}

void rotateNode(int node) {
    int temp = seg[node].cnt[2];
    seg[node].cnt[2] = seg[node].cnt[1];
    seg[node].cnt[1] = seg[node].cnt[0];
    seg[node].cnt[0] = temp;
}

void push(int node, int l, int r) {
    if (lazy[node] != 0) {
        int times = lazy[node] % 3;

        for (int i = 0; i < times; i++)
            rotateNode(node);

        if (l != r) {
            lazy[node*2] += times;
            lazy[node*2+1] += times;
        }

        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr) {
    push(node, l, r);

    if (r < ql || l > qr)
        return;

    if (ql <= l && r <= qr) {
        lazy[node] += 1;
        push(node, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(node*2, l, mid, ql, qr);
    update(node*2+1, mid+1, r, ql, qr);

    for (int i = 0; i < 3; i++)
        seg[node].cnt[i] = seg[node*2].cnt[i] + seg[node*2+1].cnt[i];
}

Node query(int node, int l, int r, int ql, int qr) {
    push(node, l, r);

    if (r < ql || l > qr)
        return {{0,0,0}};

    if (ql <= l && r <= qr)
        return seg[node];

    int mid = (l + r) / 2;
    Node left = query(node*2, l, mid, ql, qr);
    Node right = query(node*2+1, mid+1, r, ql, qr);

    Node res;
    for (int i = 0; i < 3; i++)
        res.cnt[i] = left.cnt[i] + right.cnt[i];

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N >> M) {
        build(1, 1, N);

        for (int i = 0; i < M; i++) {
            char type;
            int A, B;
            cin >> type >> A >> B;

            if (type == 'M') {
                update(1, 1, N, A, B);
            } else {
                Node ans = query(1, 1, N, A, B);
                cout << ans.cnt[0] << " "
                     << ans.cnt[1] << " "
                     << ans.cnt[2] << "\n";
            }
        }

        cout << "\n";
    }

    return 0;
}

