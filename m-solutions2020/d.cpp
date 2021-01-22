#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    ll money = 1000;
    ll property = 0;
    for (int i = 0; i < N-1; ++i) {
        if (A[i] < A[i+1]) {
            ll buy = money / A[i];
            property += buy;
            money -= buy * A[i];
        } else if (A[i] > A[i+1]) {
            ll sell = property;
            property -= sell;
            money += sell * A[i];
        }
    }
    money += property * A[N-1];
    cout << money << endl;
}
