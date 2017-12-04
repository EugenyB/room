#include <iostream>
#include <cstring>
#include <deque>

static const int N = 20;

using namespace std;

char a[N][N];

int area(int n, int row, int col) {
    int count = 0;
    deque<int> r;
    deque<int> c;

    r.push_back(row); c.push_back(col);
    a[row][col] = '*';
    while (!r.empty()) {
        count++;
        int rx = r.front(), cx = c.front();
        r.pop_front(); c.pop_front();
        if (a[rx-1][cx]=='.') {
            r.push_back(rx-1); c.push_back(cx);
            a[rx-1][cx]='*';
        }
        if (a[rx+1][cx]=='.') {
            r.push_back(rx+1); c.push_back(cx);
            a[rx+1][cx]='*';
        }
        if (a[rx][cx+1]=='.') {
            r.push_back(rx); c.push_back(cx+1);
            a[rx][cx+1]='*';
        }
        if (a[rx][cx-1]=='.') {
            r.push_back(rx); c.push_back(cx-1);
            a[rx][cx-1]='*';
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    char dummy[10];
    cin.getline(dummy,10);
//    char a[n][n+1];
    for (int i = 0; i < n; ++i) {
        cin.getline(a[i], N);
    }
    int row, col;
    cin >> row >> col;
    row--; col--;
//    for (int i = 0; i < n; ++i) {
//        cout << a[i] << endl;
//    }
    int res = area(n, row, col);
    cout << res << endl;
    return 0;
}