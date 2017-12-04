#include <iostream>
#include <cstring>

static const int N = 20;

using namespace std;

char a[N][N];

int area(int n, int row, int col) {
    int count = 0;
    int r[100], c[100];
    int k = 0;
    r[0] = row; c[0] = col; k++;
    a[row][col] = '*';
    while (k>0) {
        k--; count++;
        int rx = r[k], cx = c[k];
        if (a[rx-1][cx]=='.') {
            k++;
            r[k]=rx-1; c[k]=cx;
            a[rx-1][cx]='*';
        }
        if (a[rx+1][cx]=='.') {
            k++;
            r[k]=rx+1; c[k]=cx;
            a[rx+1][cx]='*';
        }
        if (a[rx][cx+1]=='.') {
            k++;
            r[k]=rx; c[k]=cx+1;
            a[rx][cx+1]='*';
        }
        if (a[rx][cx-1]=='.') {
            k++;
            r[k]=rx; c[k]=cx-1;
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