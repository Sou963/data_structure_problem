#include <iostream>
using namespace std;

// Simple GCD function
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int a, b, c, d;
        char slash1, slash2, op;

        // Input like: 1 / 2 + 3 / 4
        cin >> a >> slash1 >> b >> op >> c >> slash2 >> d;

        int num, den;

        if (op == '+') {
            num = a * d + c * b;
            den = b * d;
        }
        else if (op == '-') {
            num = a * d - c * b;
            den = b * d;
        }
        else if (op == '*') {
            num = a * c;
            den = b * d;
        }
        else { // division
            num = a * d;
            den = c * b;
        }

        int g = gcd(num, den);

        cout << num << "/" << den << " = "
             << num / g << "/" << den / g << endl;
    }

    return 0;
}

