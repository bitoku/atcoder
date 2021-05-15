#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll result = 0;
    for (int i = 0; i < 10000; ++i) {
        int d = i % 10;
        int c = i / 10 % 10;
        int b = i / 100 % 10;
        int a = i / 1000 % 10;
        bool ok = true;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == 'o' && (a != j && b != j && c != j && d != j)) {
                ok = false;
                break;
            }
            if (s[j] == 'x' && (a == j || b == j || c == j || d == j)) {
                ok = false;
                break;
            }
        }
        if (ok) result++;
    }
    cout << result << endl;

}