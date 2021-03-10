#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int chars[26] = {};
    for (char i : s) {
        chars[i - 'a']++;
    }
    ll result = 1;
    for (int i : chars) {
        result *= i + 1;
        result %= mod;
    }
    cout << result - 1 << endl;
}
