#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string t;
    cin >> t;
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == '?') {
            if (i == 0 || t[i-1] != '2') ) {
                t[i] = '2';
            } else {
                t[i] = '5';
            }
        }
    }
    ll cnt = 0;
    for (int i = 0; i < t.size() - 1; ++i) {
        if (t[i] == '2' && t[i+1] == '5') {

        }
    }
}