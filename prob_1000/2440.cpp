// 2438, 2439, 2440, 2441, 2442, 2445, 2522, 2446, 10991, 10992 별 찍기 문제
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n-->0) {
        for (int i=0; i<=n; i++) cout << "*";
        cout << "\n";
    }
}
