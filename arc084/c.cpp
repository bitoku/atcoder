#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template<class T>
void printVector(vector<T> &a, string delimiter) {
    if (a.size() == 0) return;
    cout << a[0];
    for (int i = 1; i < a.size(); ++i) {
        cout << delimiter << a[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> bb(n);
    vector<ll> c(n);
    vector<ll> cc(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int ai = 0;
    for (int bi = 0; bi < n; ++bi){
        if (bi != 0) {
            bb[bi] = bb[bi-1];
        }
        for (; ai < n; ++ai) {
            if (b[bi] <= a[ai]) {
                break;
            }
            bb[bi]++;
        }
    }
    int bi = 0;
    for (int ci = 0; ci < n; ++ci){
        if (ci != 0) {
            cc[ci] = cc[ci-1];
        }
        for (; bi < n; ++bi) {
            if (c[ci] <= b[bi]) {
                break;
            }
            cc[ci] += bb[bi];
        }
    }
    ll result = 0;
    for (int ci = 0; ci < n; ++ci) {
        result += cc[ci];
    }
    cout << result << endl;
}