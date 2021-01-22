#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    string s;
    cin >> s;
    vector<int> x(s.size());
    vector<int> result(s.size());
    int lastRL = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'L') {
            int idx = (i - lastRL) % 2 == 0 ? lastRL : lastRL - 1;
            result[idx]++;
        } else if (s[i] == 'R' && s[i+1] == 'L') {
            result[i]++;
            for (int j = i - 1; j >= 0 && s[j] == 'R'; --j) {
                int idx = (i - j) % 2 == 1 ? i + 1 : i;
                result[idx]++;
            }
            lastRL = i+1;
        }
    }
    printVector(result, " ");
}
