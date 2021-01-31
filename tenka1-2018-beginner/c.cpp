#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

template<class T>
void printVector(deque<T> &a, string delimiter) {
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    deque<int> b;
    b.push_back(a[0]);
    int cnt = 1;
    int k = n - 1;
    while (cnt < n) {
        b.push_front(a[k]);
        cnt++;
        if (cnt >= n) break;
        b.push_back(a[k-1]);
        cnt++;
        k = n - k;
        if (cnt >= n) break;
        b.push_front(a[k]);
        cnt++;
        if (cnt >= n) break;
        b.push_back(a[k+1]);
        k = n - k - 2;
        cnt++;
    }
    ll result = 0;
    for (int i = 1; i < n; ++i) {
        result += abs(b[i-1] - b[i]);
    }

    deque<int> c;
    c.push_back(a[n-1]);
    cnt = 1;
    k = 0;
    while (cnt < n) {
        c.push_front(a[k]);
        cnt++;
        if (cnt >= n) break;
        c.push_back(a[k+1]);
        cnt++;
        k = n - k - 2;
        if (cnt >= n) break;
        c.push_front(a[k]);
        cnt++;
        if (cnt >= n) break;
        c.push_back(a[k-1]);
        k = n - k;
        cnt++;
    }

    ll resultc = 0;
    for (int i = 1; i < n; ++i) {
        resultc += abs(c[i-1] - c[i]);
    }
    cout << max(result, resultc) << endl;
}
