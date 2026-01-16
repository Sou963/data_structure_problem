#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M, N;
    cin >> M >> N;
    unordered_map<string, long long> dict;
    string word;
    long long value;
    for (int i = 0; i < M; i++)
    {
        cin >> word >> value;
        dict[word] = value;
    }
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        long long salary = 0;
        string line;

        while (getline(cin, line))
        {
            if (line == ".")
                break;

            stringstream ss(line);
            while (ss >> word)
            {
                if (dict.count(word))
                {
                    salary += dict[word];
                }
            }
        }
        cout << salary << "\n";
    }

    return 0;
}

