// 2438, 2439, 2440, 2441, 2442, 2445, 2522, 2446, 10991, 10992 별 찍기 문제
// 2445, 2522에서 참고한 방법대로 풀었음
#include <iostream>
using namespace std;

int main() {
    int n, i, j, k=1;
    cin >> n;
    for (i=0; i>=0; i+=k) {
        for (j=0; j<i; j++) cout << " ";
        for (j=0; j<2*(n-i)-1; j++) cout << "*";
        cout << " \n";
        if (i==n-1) k=-1;
    }
}
