#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, int>> v(n+1, {-1, -1});
    for (int i = n - 1; i >= 0; --i) {
        v[i] = v[i+1];
        if (s[i] == 'o') v[i].first = i;
        else v[i].second = i;
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o' && v[i].second != -1) result += n - v[i].second;
        if (s[i] == 'x' && v[i].first != -1) result += n - v[i].first;
    }
    cout << result << endl;
}