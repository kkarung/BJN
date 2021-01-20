// 예제 출력을 드래그해보면 어디 공백이 필요한 지 알 수 있음!!
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int j;
        for (j=0; j<n-i; j++) cout << " ";
        for (j=0; j<2*i-1; j++) cout << "*";
        if (i!=n) cout << " ";
        cout << "\n";
    }
}
