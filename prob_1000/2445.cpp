// 2438, 2439, 2440, 2441, 2442, 2445, 2522, 2446, 10991, 10992 별 찍기 문제
#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    cin >> n;
    for (i=1; i<=n-1; i++) {
        for (j=1; j<=i; j++) cout << "*";
        for (j=1; j<=(n-i)*2; j++) cout << " ";
        for (j=1; j<=i; j++) cout << "*";
        cout << " \n";
    }
    for (i=0; i<2*n; i++) cout << "*";
    cout << " \n";
    for (i=n-1; i>=1; i--) {
        for (j=1; j<=i; j++) cout << "*";
        for (j=1; j<=(n-i)*2; j++) cout << " ";
        for (j=1; j<=i; j++) cout << "*";
        if (i!=1) cout << " \n";
    }
}
