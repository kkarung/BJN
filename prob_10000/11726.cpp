/////////////////////////
// 2021.01.28 / kkarung /
//   DP / Bottom-up
/////////////////////////
#include <iostream>
using namespace std;

int main() {
    int n;
    int list[1001];
    list[1]=1;  list[2]=2; list[3]=3;
    cin >> n;
    for (int i=4; i<=n; i++) {
        list[i] = i%2 ? list[i-1]+list[i-2] : list[i-2]*2+list[i-3];
        list[i] %= 10007;
    }
    cout << list[n];
}


////// 개선: 그냥 피보나치 수열이다 ///////
// 삼항연산자를 그냥 피보나치수열로 변환하자 //
#include <iostream>
using namespace std;

int main() {
    int n;
    int list[1001];
    list[1]=1;  list[2]=2; list[3]=3;
    cin >> n;
    for (int i=4; i<=n; i++)
        list[i] = (list[i-1]+list[i-2])%10007;
    cout << list[n];
}
