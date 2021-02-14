#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

char battle(char a, char b) {
    if (a == b) {
        return a;
    }
    if (a == 'R') {
        if (b == 'S') {
            return a;
        } else {
            return b;
        }
    }
    if (a == 'S') {
        if (b == 'P') {
            return a;
        } else {
            return b;
        }
    }
    if (a == 'P') {
        if (b == 'R') {
            return a;
        } else {
            return b;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (; k > 0; --k) {
        if (s.size() == 1) {
            cout << s[0] << endl;
            return 0;
        }
        string winner;
        winner.push_back(battle(s[0], s[1]));
        for (int i = 2 % s.size(); i != 0 ; i = (i + 2) % s.size()) {
            winner.push_back(battle(s[i], s[(i+1) % s.size()]));
        }
        s = winner;
    }
    cout << s.front() << endl;
}
