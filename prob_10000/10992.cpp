// 2438, 2439, 2440, 2441, 2442, 2445, 2522, 2446, 10991, 10992 별 찍기 문제
// i=0부터 n-1까지 두는 게 더 간편한 풀이인 듯(https://www.acmicpc.net/source/20610763)
#include <iostream>
using namespace std;

int main() {
    int n, i, j;
    cin >> n;
    for (i=1; i<=n; i++) {
        for (j=0; j<n-i; j++) cout << " ";
        if (i==1||i==n) {
            for (j=0;j<2*i-1; j++) cout << "*";
        } else {
            cout << "*";
            for (j=0; j<2*i-3; j++) cout << " ";
            cout << "*";
        }
        
        cout << " \n";
    }
}
