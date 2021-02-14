#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

int main() {
    int t;
    cin >> t;
    string atcoder = "atcoder";
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        bool big = false;
        if (s.size() > atcoder.size() && s.substr(0, atcoder.size()) == atcoder) {
            cout << 0 << endl;
            continue;
        }
        for (int j = 0; j < atcoder.size(); ++j) {
            if (s[j] > atcoder[j]) {
                big = true;
                break;
            } else if (s[j] < atcoder[j]) {
                break;
            }
        }
        if (big) {
            cout << 0 << endl;
            continue;
        }
        if (s[0] != 'a') {
            cout << 0 << endl;
            continue;
        }
        int nota = -1;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] != 'a') {
                nota = j;
                break;
            }
        }
        if (nota == -1) {
            cout << -1 << endl;
        } else {
            if (s[nota] > 't') {
                cout << nota - 1 << endl;
            } else {
                cout << nota << endl;
            }
        }
    }
}
