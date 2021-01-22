#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int A, B, C;
    int K;
    cin >> A >> B >> C;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        if (A >= B) B *= 2;
        else if (B >= C) C *= 2;
        else break;
    }
    if (A < B && B < C) cout << "Yes" << endl;
    else cout << "No" << endl;
}
