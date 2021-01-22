#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> score(N, vector<ll>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> score[i][j];
        }
    }
    ll m = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            ll sc = 0;
            for (int k = 0; k < N; ++k) {
                sc += max(score[k][i], score[k][j]);
            }
            m = max(sc, m);
        }
    }

    cout << m << endl;
}
