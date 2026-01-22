#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        stack<int> st;
        queue<int> qu;
        priority_queue<int> pq;

        bool isStack = true;
        bool isQueue = true;
        bool isPQ = true;

        for (int i = 0; i < n; i++) {
            int type, x;
            cin >> type >> x;

            if (type == 1) {
                if (isStack) st.push(x);
                if (isQueue) qu.push(x);
                if (isPQ) pq.push(x);
            } else { // type == 2
                if (isStack) {
                    if (st.empty() || st.top() != x)
                        isStack = false;
                    else
                        st.pop();
                }

                if (isQueue) {
                    if (qu.empty() || qu.front() != x)
                        isQueue = false;
                    else
                        qu.pop();
                }

                if (isPQ) {
                    if (pq.empty() || pq.top() != x)
                        isPQ = false;
                    else
                        pq.pop();
                }
            }
        }

        int cnt = isStack + isQueue + isPQ;

        if (cnt == 0)
            cout << "impossible\n";
        else if (cnt > 1)
            cout << "not sure\n";
        else if (isStack)
            cout << "stack\n";
        else if (isQueue)
            cout << "queue\n";
        else
            cout << "priority queue\n";
    }

    return 0;
}

