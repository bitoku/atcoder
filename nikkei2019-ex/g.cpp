#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    string s;
    cin >> s;
    ll c[26] = {};
    for (int i = 0; i < s.size(); ++i) {
        c[s[i]-'a']++;
    }
    ll result = 0;
    ll temp = 0;
    for (int j = 0; j < 26; ++j) {
        temp += c[j] / 2;
    }
    temp *= 2;
    temp *= temp;
    for (int j = 0; j < 26; ++j) {
        temp += c[j] % 2;
    }
    result = max(result, temp);
    for (int i = 0; i < 26; ++i) {
        if (c[i] == 0) continue;
        temp = 0;
        c[i]--;
        for (int j = 0; j < 26; ++j) {
            temp += c[j] / 2;
        }
        temp *= 2;
        temp++;
        temp *= temp;
        for (int j = 0; j < 26; ++j) {
            temp += c[j] % 2;
        }
        result = max(result, temp);
        c[i]++;
    }
    cout << result << endl;
}