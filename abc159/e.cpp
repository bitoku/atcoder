#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int count(const vector<string>& v, int y1, int y2, int x) {
    int ans = 0;
    for (int i=y1;i<=y2;i++) {
        if (v[i][x] == '1') ans++;
    }
    return ans;
}

int main() {
    int h, w, k;
    vector<string> v;
    cin >> h >> w >> k;
    for (int i=0;i<h;i++) {
        string x;
        cin >> x;
        v.push_back(x);
    }
    int horizontal = int(pow(2, h-1));
    int m_line = 100000;
    for (int i=0;i<horizontal;i++) {
        vector<int> vh;
        int line;
        int hor = i;
        vh.push_back(0);
        for (int j=1;j<=h-1;j++) {
            if (hor & 1) {
                vh.push_back(j);
            }
            hor >>= 1;
        }
        vh.push_back(h);
        line = int(vh.size() - 2);

        vector<int> vv(line+1);

//        for (auto l: vh) {
//            cout << l << ' ';
//        }
//        cout << endl;

        for (int x=0; x<w; x++) {
            vector<int> vvv;

            for (int j=0;j<vh.size()-1;j++) {
                int y1 = vh[j];
                int y2 = vh[j+1] - 1;
                vvv.push_back(count(v, y1, y2, x));
            }
            for(int j=0;j<vv.size();j++) {
                if (vvv[j] > k) {
                    line = m_line;
                }
                if (vv[j] + vvv[j] > k) {
                    copy(vvv.begin(), vvv.end(), vv.begin());
                    line++;
                    break;
                }

                vv[j] += vvv[j];
            }
            if (line >= m_line) {
                break;
            }
        }
        if (line < m_line) {
            m_line = line;
        }
    }
    cout << m_line << endl;
}
