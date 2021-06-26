#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 06/26

struct Cake {
    ll x;
    ll y;
    ll z;
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<Cake> cakes(n);
    for (int i = 0; i < n; ++i) {
        cin >> cakes[i].x >> cakes[i].y >> cakes[i].z;
    }
    priority_queue<ll> xyz[8];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) {
            ll sum = 0;
            if (j & 0b1) sum += cakes[i].x;
            else sum -= cakes[i].x;
            if (j & 0b10) sum += cakes[i].y;
            else sum -= cakes[i].y;
            if (j & 0b100) sum += cakes[i].z;
            else sum -= cakes[i].z;
            xyz[j].push(sum);
        }
    }
    ll sum[8] = {};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 8; ++j) {
            sum[j] += xyz[j].top(); xyz[j].pop();
        }
    }
    ll result = 0;
    for (int i = 0; i < 8; ++i) {
        result = max(result, sum[i]);
    }
    cout << result << endl;
}