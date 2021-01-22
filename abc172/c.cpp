#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class T>
void printIter(const T &a, string delimiter) {
    if (a.size() == 0) return;
    auto it = a.begin();
    cout << *it;
    it++;
    while (it != a.end()) {
        cout << delimiter << *it;
        it++;
    }
    cout << endl;
}

int main() {
    ll N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    vector<ll> B(M);
    vector<ll> sumA(N);
    vector<ll> sumB(M);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i == 0) sumA[0] = A[i];
        else sumA[i] = sumA[i-1] + A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        if (i == 0) sumB[0] = B[i];
        else sumB[i] = sumB[i-1] + B[i];
    }
    ll m = 0;
    for (int i = 0; i < N; ++i) {
        ll k = sumA[i];
        ll tempm = 0;
        if (k > K) break;
        tempm = i + 1;
        auto it = upper_bound(sumB.begin(), sumB.end(), K-k);
//        cout << k << ' ' << *(it-1) << endl;
//        cout << tempm << ' ' << (ll)distance(sumB.begin(), it) << endl;
        tempm += (ll)distance(sumB.begin(), it);
        m = max(m, tempm);
    }
    auto it = upper_bound(sumB.begin(), sumB.end(), K);
    ll tempm = (ll)distance(sumB.begin(), it);
    m = max(m, tempm);
    cout << m << endl;
}

