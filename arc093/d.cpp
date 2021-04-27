#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 04/27 AC

int main() {
    ll a, b;
    cin >> a >> b;
    a--; b--;
    cout << 100 << ' ' << 100 << endl;
    for (int i = 0; i < 50; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < 100; ++j) {
                cout << '#';
            }
            cout << endl;
            continue;
        }
        for (int j = 0; j < 50; ++j) {
            if (a == 0) {
                cout << "##";
                continue;
            }
            cout << "#.";
            a--;
        }
        cout << endl;
    }
    for (int i = 0; i < 50; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < 100; ++j) {
                cout << '.';
            }
            cout << endl;
            continue;
        }
        for (int j = 0; j < 50; ++j) {
            if (b == 0) {
                cout << "..";
                continue;
            }
            cout << ".#";
            b--;
        }
        cout << endl;
    }
}