#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string infix;
        cin >> infix;

        stack<char> st;
        string postfix = "";

        for (char c : infix) {
            if (isalnum(c)) {
                postfix += c;
            }
            else if (c == '(') {
                st.push(c);
            }
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() &&
                       st.top() != '(' &&
                       (precedence(st.top()) > precedence(c) ||
                       (precedence(st.top()) == precedence(c) && !isRightAssociative(c)))) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        cout << postfix << "\n";
    }

    return 0;
}

