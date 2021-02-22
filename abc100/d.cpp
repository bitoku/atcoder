#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

struct P {
    ll x;
    ll y;
    ll z;
};

ll abs(P p) {
    return abs(p.x) + abs(p.y) + abs(p.z);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y >> v[i].z;
    }
    P p = {0};
    ll result = 0;
    sort(v.begin(), v.end(), [](P& a, P& b) {
        return a.x + a.y + a.z < b.x + b.y + b.z;
    });
    for (int i = 0; i < m; ++i) {
        p.x += v[i].x;
        p.y += v[i].y;
        p.z += v[i].z;
    }
    result = max(result, abs(p));
    sort(v.begin(), v.end(), [](P& a, P& b) {
        return a.x + a.y - a.z < b.x + b.y - b.z;
    });
    p = {0};
    for (int i = 0; i < m; ++i) {
        p.x += v[i].x;
        p.y += v[i].y;
        p.z += v[i].z;
    }
    result = max(result, abs(p));
    sort(v.begin(), v.end(), [](P& a, P& b) {
        return a.x - a.y + a.z < b.x - b.y + b.z;
    });
    p = {0};
    for (int i = 0; i < m; ++i) {
        p.x += v[i].x;
        p.y += v[i].y;
        p.z += v[i].z;
    }
    result = max(result, abs(p));
    sort(v.begin(), v.end(), [](P& a, P& b) {
        return a.x - a.y - a.z < b.x - b.y - b.z;
    });
    p = {0};
    for (int i = 0; i < m; ++i) {
        p.x += v[i].x;
        p.y += v[i].y;
        p.z += v[i].z;
    }
    result = max(result, abs(p));
    sort(v.begin(), v.end(), [](P& a, P& b) {
        return - a.x + a.y + a.z < - b.x + b.y + b.z;
    });
    p = {0};
    for (int i = 0; i < m; ++i) {
        p.x += v[i].x;
        p.y += v[i].y;
        p.z += v[i].z;
    }
    result = max(result, abs(p));
    sort(v.begin(), v.end(), [](P& a, P& b) {
        return - a.x + a.y - a.z < - b.x + b.y - b.z;
    });
    p = {0};
    for (int i = 0; i < m; ++i) {
        p.x += v[i].x;
        p.y += v[i].y;
        p.z += v[i].z;
    }
    result = max(result, abs(p));
    sort(v.begin(), v.end(), [](P& a, P& b) {
        return - a.x - a.y + a.z < - b.x - b.y + b.z;
    });
    p = {0};
    for (int i = 0; i < m; ++i) {
        p.x += v[i].x;
        p.y += v[i].y;
        p.z += v[i].z;
    }
    result = max(result, abs(p));
    sort(v.begin(), v.end(), [](P& a, P& b) {
        return - a.x - a.y - a.z < - b.x - b.y - b.z;
    });
    p = {0};
    for (int i = 0; i < m; ++i) {
        p.x += v[i].x;
        p.y += v[i].y;
        p.z += v[i].z;
    }
    result = max(result, abs(p));
    cout << result << endl;
}
