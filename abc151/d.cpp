#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool warshallfloyd(
        vector<vector<long long>>& dist
        ) {
    for (int k = 0; k < dist.size(); ++k) {
        for (int i = 0; i < dist.size(); ++i) {
            for (int j = 0; j < dist.size(); ++j) {
                if (dist[i][k] == LONG_LONG_MAX || dist[k][j] == LONG_LONG_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < dist.size(); ++i) {
        if (dist[i][i] < 0) return false;
    }
    return true;
}

int main() {
    vector<string> s;
    int H, W;
    cin >> H >> W;
    s.push_back(string(W+2, '#'));
    for (int i = 0; i < H; ++i) {
        string ss;
        cin >> ss;
        ss = '#' + ss + '#';
        s.push_back(ss);
    }
    s.push_back(string(W+2, '#'));

    vector<vector<ll>> dist((H+2)*(W+2), vector<ll>((H+2)*(W+2), LONG_LONG_MAX));
    for (int i = 0; i < dist.size(); ++i) {
        dist[i][i] = 0;
    }
    for (int i = 1; i <= H; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (s[i][j] == '#') continue;
            if (s[i-1][j] == '.') {
                dist[i*W+j][(i-1)*W+j] = 1;
                dist[(i-1)*W+j][i*W+j] = 1;
            }
            if (s[i+1][j] == '.') {
                dist[i*W+j][(i+1)*W+j] = 1;
                dist[(i+1)*W+j][i*W+j] = 1;
            }
            if (s[i][j-1] == '.') {
                dist[i*W+j][i*W+j-1] = 1;
                dist[i*W+j-1][i*W+j] = 1;
            }
            if (s[i][j+1] == '.') {
                dist[i*W+j][i*W+j+1] = 1;
                dist[i*W+j+1][i*W+j] = 1;
            }
        }
    }
    warshallfloyd(dist);
    ll m = 0;
    for (int i = 0; i < dist.size(); ++i) {
        for (int j = 0; j < dist.size(); ++j) {
            if (dist[i][j] == LONG_LONG_MAX) continue;
            m = max(dist[i][j], m);
        }
    }
    cout << m << endl;
}
