#include <bits/stdc++.h>
using namespace std;

void compressBlock(char symbol, int count) {
    while (count > 255) {
        cout << symbol;
        cout << char(255);
        count -= 255;
    }
    if (count > 0) {
        cout << symbol;
        cout << char(count);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    cin.ignore();

    while (N--) {
        string s;
        getline(cin, s);

        int n = s.size();
        string out = "";

        for (int i = 0; i < n; ) {
            if (s[i] == ' ') {
                int j = i;
                while (j < n && s[j] == ' ') j++;

                int count = j - i;
                if (count >= 3)
                    compressBlock('$', count);
                else
                    cout << string(count, ' ');

                i = j;
            }
            else if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;

                int count = j - i;
                if (count >= 3)
                    compressBlock('#', count);
                else
                    cout << string(count, '0');

                i = j;
            }
            else {
                cout << s[i];
                i++;
            }
        }
        cout << "\n";
    }

    return 0;
}

