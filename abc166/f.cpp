#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    ll k[3];
    cin >> n >> k[0] >> k[1] >> k[2];
    vector<string> s(n);
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i] == "AC") s[i] = "CA";
        p[i].first = s[i][0]-'A';
        p[i].second = s[i][1]-'A';
    }
    vector<char> ope(n);
    for (int i = 0; i < n; ++i) {
        if (k[p[i].first] == 0 && k[p[i].second] == 0) {
            cout << "No" << endl;
            return 0;
        } else if (k[p[i].first] == 0) {
            ope[i] = s[i][0];
            k[p[i].first]++;
            k[p[i].second]--;
        } else if (k[p[i].second] == 0) {
            ope[i] = s[i][1];
            k[p[i].first]--;
            k[p[i].second]++;
        } else {
            if (i == n-1) {
                ope[i] = s[i][0];
            } else {
                if (p[i].first == p[i+1].first && p[i].second == p[i+1].second) {
                    ope[i] = s[i][0];
                    k[p[i].first]++;
                    k[p[i].second]--;
                } else if (p[i].first == p[i+1].second) {
                    ope[i] = s[i][0];
                    k[p[i].first]++;
                    k[p[i].second]--;
                } else if (p[i].second == p[i+1].first) {
                    ope[i] = s[i][1];
                    k[p[i].first]--;
                    k[p[i].second]++;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ope[i] << endl;
    }
}