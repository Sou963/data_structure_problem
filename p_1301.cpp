#include <bits/stdc++.h>
using namespace std;

struct Node {
    int zero, neg;
};

vector<Node> seg;
vector<int> arr;
int N;

Node mergeNode(const Node &a, const Node &b) {
    return {a.zero + b.zero, a.neg + b.neg};
}

void build(int idx, int l, int r) {
    if (l == r) {
        if (arr[l] == 0) seg[idx] = {1, 0};
        else if (arr[l] < 0) seg[idx] = {0, 1};
        else seg[idx] = {0, 0};
        return;
    }
    int mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
}

void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        if (val == 0) seg[idx] = {1, 0};
        else if (val < 0) seg[idx] = {0, 1};
        else seg[idx] = {0, 0};
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(idx * 2, l, mid, pos, val);
    else update(idx * 2 + 1, mid + 1, r, pos, val);
    seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return {0, 0};
    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) / 2;
    Node left = query(idx * 2, l, mid, ql, qr);
    Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);
    return mergeNode(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    while (cin >> N >> K) {
        arr.resize(N + 1);
        seg.assign(4 * N, {0, 0});

        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        build(1, 1, N);

        string result = "";

        while (K--) {
            char cmd;
            cin >> cmd;
            if (cmd == 'C') {
                int i, v;
                cin >> i >> v;
                update(1, 1, N, i, v);
            } else { // 'P'
                int i, j;
                cin >> i >> j;
                Node res = query(1, 1, N, i, j);
                if (res.zero > 0) result += '0';
                else if (res.neg % 2 == 0) result += '+';
                else result += '-';
            }
        }

        cout << result << "\n";
    }

    return 0;
}
