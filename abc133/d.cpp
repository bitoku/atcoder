#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }
    ll prev = sum;
    for (int i = 1; i < N; i += 2) {
        prev -= 2 * A[i];
    }
    cout << prev;
    for (int i = 0; i < N-1; ++i) {
        prev = 2 * A[i] - prev;
        cout << ' ' << prev;
    }
    cout << endl;

}
