#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        x[i] = abs(x[i]);
    }
    ll m = 0;
    ll e = 0;
    ll c = 0;
    for (int i = 0; i < N; ++i) {
        m += x[i];
        e += x[i] * x[i];
    }
    cout << m << endl;
    cout << setprecision(15) << sqrt(e) << endl;
    cout << *(max_element(x.begin(), x.end())) << endl;
}
