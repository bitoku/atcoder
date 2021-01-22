#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double ax, ay, bx, by;
    int passed = h * 60 + m;
    double rada = M_PI / 2 - double(passed) / 720 * 2 * M_PI;
    double radb = M_PI / 2 - double(m) / 60 * 2 * M_PI;
    ax = a * cos(rada);
    ay = a * sin(rada);
    bx = b * cos(radb);
    by = b * sin(radb);
    cout << setprecision(15) << sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by)) << endl;
    return 0;
}
