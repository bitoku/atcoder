#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    reverse(s[0].begin(), s[0].end());
    reverse(s[1].begin(), s[1].end());
    reverse(s[2].begin(), s[2].end());
    int turn = 0;
    while (!s[turn].empty()) {
        char c = s[turn].back();
        s[turn].pop_back();
        if (c == 'a') turn = 0;
        else if (c == 'b') turn = 1;
        else if (c == 'c') turn = 2;
    }
    if (turn == 0) cout << 'A' << endl;
    else if (turn == 1) cout << 'B' << endl;
    else cout << 'C' << endl;
}
