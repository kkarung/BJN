// printf("%5d"); 서식을 빌려 for문을 줄여보려 했으나 printf("%nd")가 되어 실패함
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=n-i; j>0; j--) cout << " ";
        for (int j=1; j<=i; j++) cout << "*";
        cout << "\n";
    }
}
