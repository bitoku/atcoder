#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string t;
    cin >> t;
    ll cnt = 0;
    ll result = 0;
    for (int i = 0; i < t.size() - 1; i+=2) {
        if ((t[i] == '2' || t[i] == '?') && (t[i+1] == '5' || t[i+1] == '?')) {
            cnt++;
        } else {
            result = max(cnt, result);
            cnt = 0;
        }
    }
    result = max(cnt, result);
    cnt = 0;
    for (int i = 1; i < t.size() - 1; i+=2) {
        if ((t[i] == '2' || t[i] == '?') && (t[i+1] == '5' || t[i+1] == '?')) {
            cnt++;
        } else {
            result = max(cnt, result);
            cnt = 0;
        }
    }
    result = max(cnt, result);

    cout << result * 2 << endl;
}