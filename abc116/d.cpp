#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> sushi(n);
    for (int i = 0; i < n; ++i) {
        cin >> sushi[i].second >> sushi[i].first;
    }
    sort(sushi.begin(), sushi.end(), greater<>());
    map<ll, ll> neta;
    ll result = 0;
    ll temp = 0;
    ll netacnt = 0;
    priority_queue<pair<ll, ll>> init;
    for (int i = 0; i < k; ++i) {
        if (neta.find(sushi[i].second) == neta.end()) netacnt++;
        neta[sushi[i].second]++;
        temp += sushi[i].first;
        init.push(sushi[i]);
    }
    result = temp + netacnt * netacnt;
    int l = k;
    for (int i = k; i < n; ++i) {
        if (neta.find(sushi[i].second) != neta.end()) continue;
        neta[sushi[i].second]++;
        temp += sushi[i].first;
        netacnt++;
        while (l > 0) {
            --l;
            if (neta[sushi[l].second] > 1) {
                neta[sushi[l].second]--;
                temp -= sushi[l].first;
                result = max(result, temp + netacnt * netacnt);
                break;
            }
        }
        if (l <= 0) break;
    }
    cout << result << endl;
}
