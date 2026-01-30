#include <bits/stdc++.h>
using namespace std;

struct State {
    int pc;
    array<int, 10> r;

    bool operator<(State const& other) const {
        if (pc != other.pc) return pc < other.pc;
        return r < other.r;
    }
};

int L;
vector<string> prog;
map<int, int> endifJump;

/* Executes program starting with R0 = input
   Returns pair {halts?, return_value} */
pair<bool, int> run(int input) {
    array<int,10> R{};
    R.fill(0);
    R[0] = input;

    int pc = 0;
    set<State> visited;

    while (true) {
        State cur{pc, R};
        if (visited.count(cur))
            return {false, 0}; // infinite loop
        visited.insert(cur);

        string line = prog[pc];
        string cmd;
        string arg;
        {
            stringstream ss(line);
            ss >> cmd;
            getline(ss, arg);
            if (!arg.empty() && arg[0] == ' ')
                arg.erase(arg.begin());
        }

        auto getVal = [&](string s) {
            if (s[0] == 'R') return R[s[1] - '0'];
            return stoi(s);
        };

        auto setVal = [&](string s, int v) {
            R[s[1] - '0'] = ((v % 1000) + 1000) % 1000;
        };

        if (cmd == "MOV" || cmd == "ADD" || cmd == "SUB" ||
            cmd == "MUL" || cmd == "DIV" || cmd == "MOD") {

            int comma = arg.find(',');
            string a = arg.substr(0, comma);
            string b = arg.substr(comma + 1);

            int v = getVal(b);
            int &x = R[a[1] - '0'];

            if (cmd == "MOV") x = v;
            else if (cmd == "ADD") x += v;
            else if (cmd == "SUB") x -= v;
            else if (cmd == "MUL") x *= v;
            else if (cmd == "DIV") x = (v == 0 ? 0 : x / v);
            else if (cmd == "MOD") x = (v == 0 ? 0 : x % v);

            x = (x % 1000 + 1000) % 1000;
            pc++;
        }

        else if (cmd.substr(0,2) == "IF") {
            int comma = arg.find(',');
            string a = arg.substr(0, comma);
            string b = arg.substr(comma + 1);

            int v1 = getVal(a);
            int v2 = getVal(b);

            bool cond = false;
            if (cmd == "IFEQ") cond = (v1 == v2);
            else if (cmd == "IFNEQ") cond = (v1 != v2);
            else if (cmd == "IFG") cond = (v1 > v2);
            else if (cmd == "IFL") cond = (v1 < v2);
            else if (cmd == "IFGE") cond = (v1 >= v2);
            else if (cmd == "IFLE") cond = (v1 <= v2);

            if (cond) pc++;
            else pc = endifJump[pc] + 1;
        }

        else if (cmd == "ENDIF") {
            pc++;
        }

        else if (cmd == "CALL") {
            int v = getVal(arg);
            auto res = run(v);
            if (!res.first) return {false, 0};
            R[9] = res.second;
            pc++;
        }

        else if (cmd == "RET") {
            int v = getVal(arg);
            return {true, v};
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int N;
        cin >> L >> N;
        if (L == 0 && N == 0) break;

        prog.clear();
        cin.ignore();

        for (int i = 0; i < L; i++) {
            string s;
            getline(cin, s);
            prog.push_back(s);
        }

        // Match IF ↔ ENDIF
        stack<int> st;
        endifJump.clear();
        for (int i = 0; i < L; i++) {
            if (prog[i].substr(0,2) == "IF")
                st.push(i);
            else if (prog[i] == "ENDIF") {
                int x = st.top(); st.pop();
                endifJump[x] = i;
            }
        }

        auto ans = run(N);
        if (!ans.first) cout << "*\n";
        else cout << ans.second << "\n";
    }
    return 0;
}

