#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

bool include(string& a, string& b) {
    return a.size() >= b.size() && a.substr(0, b.size()) == b;
}

int main() {
    ll n, k;
    cin >> n >> k;
    set<int> a;
    for (int i = 0; i < k; ++i) {
        int aa;
        cin >> aa;
        aa--;
        a.insert(aa);
    }
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {return s[i] < s[j];});
    bool found = false;
    int x = 0;
    int mini = 0;
    int maxi = 0;
    for (int i = 0; i < n; ++i) {
        if (a.find(idx[i]) != a.end()) {
            if (!found) {
                found = true;
                mini = i;
            }
            maxi = i;
            x++;
        } else if (found) {
            break;
        }
    }
    if (x != k) {
        cout << -1 << endl;
        return 0;
    }
    string mins;
    if (mini > 0) {
        int i = 0;
        string sprev = s[idx[mini-1]];
        string scur = s[idx[mini]];
        if (sprev == scur) {
            cout << -1 << endl;
            return 0;
        }
        for (; i < sprev.size() && i < scur.size(); ++i) {
            mins.push_back(scur[i]);
            if (sprev[i] != scur[i]) {
                break;
            }
        }
        if (sprev == mins) {
            mins.push_back(scur[i]);
        }
    }
    string maxs;
    if (maxi < n - 1) {
        int i = 0;
        string scur = s[idx[maxi]];
        string snext = s[idx[maxi+1]];
        if (snext == scur) {
            cout << -1 << endl;
            return 0;
        }
        for (; i < snext.size() && i < scur.size(); ++i) {
            maxs.push_back(scur[i]);
            if (snext[i] != scur[i]) {
                break;
            }
        }
        if (snext == maxs) {
            maxs.push_back(scur[i]);
        }
    }
    if (mins == maxs) {
        cout << mins << endl;
    } else if (mins.size() < maxs.size() && include(s[idx[mini]], maxs)) {
        cout << maxs << endl;
    } else if (maxs.size() < mins.size() && include(s[idx[maxi]], mins)) {
        cout << mins << endl;
    } else {
        cout << -1 << endl;
    }
}