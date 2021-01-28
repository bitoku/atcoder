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
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> cake(h);
    vector<vector<int>> sections(h);
    for (int i = 0; i < h; ++i) {
        cin >> cake[i];
    }
    int cnt = 1;
    vector<int> top_line;
    for (int i = 0; i < h; ++i) {
        vector<int> section(w);
        bool encountered = false;
        for (int j = 0; j < w; ++j) {
            if (cake[i][j] == '#') {
                if (encountered) {
                    cnt++;
                }
                encountered = true;
            }
            section[j] = cnt;
        }
        if (encountered) {
            cnt++;
            if (top_line.empty()) {
                top_line = section;
            }
            sections[i] = section;
        }
    }
    for (int i = 0; i < h; ++i) {
        if (sections[i].empty()) {
            printVector(top_line, " ");
        } else {
            printVector(sections[i], " ");
            top_line = sections[i];
        }
    }
}
