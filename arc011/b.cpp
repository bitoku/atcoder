#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<string> s(n);
    string result;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        string t;
        for (int j = 0; j < s[i].size(); ++j) {
            if ('A' <= s[i][j] && s[i][j] <= 'Z') s[i][j] = s[i][j] - 'A' + 'a';
            switch (s[i][j]) {
                case 'b':
                case 'c':
                    t.push_back('1');
                    break;
                case 'd':
                case 'w':
                    t.push_back('2');
                    break;
                case 't':
                case 'j':
                    t.push_back('3');
                    break;
                case 'f':
                case 'q':
                    t.push_back('4');
                    break;
                case 'l':
                case 'v':
                    t.push_back('5');
                    break;
                case 's':
                case 'x':
                    t.push_back('6');
                    break;
                case 'p':
                case 'm':
                    t.push_back('7');
                    break;
                case 'h':
                case 'k':
                    t.push_back('8');
                    break;
                case 'n':
                case 'g':
                    t.push_back('9');
                    break;
                case 'z':
                case 'r':
                    t.push_back('0');
                    break;
            }
        }
        if (t.empty()) continue;
        result += t;
        result.push_back(' ');
    }
    if (!result.empty()) result.pop_back();
    cout << result << endl;
}