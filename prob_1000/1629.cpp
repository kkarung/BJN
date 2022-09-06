/////////////////////////
// 2022.09.05/ kkarung //
//  Divide and Conquer //
/////////////////////////
//////////////////////////// report //////////////////////////////////
// for문을 이용해 b번 반복하여 곱한다면 최대 21억번 곱해야하므로 시간 초과
// 분할 정복 방법을 사용하면 log(n)의 시간 복잡도를 가진다(최대 31번)
// ∵ 마스터 정리에 따르면 T(n)=T(n/2)+O(1) 이므로 O(logn)
// (a가 1인 이유는 a의 11승은 a의 6승과 a의 5승으로 나눌 수 있으므로 둘 중 하나만
// 구하면 나머지는 구해진 것과 다름없기 때문이다
// 만약 23~28번째 줄 대신 return product(d/2) * product(d-d/2) 하면
// T(n)=2T(n/2)+O(1) => O(n)이 되므로 시간초과 된다)
// (c가 O(1)인 이유는 26번째 or 28번째 줄에서 * 연산이 최대 2번이기 때문)
// 참고: https://blog.naver.com/kks227/220776241154

#include <iostream>
using namespace std;

int a, b, c;

long long int product (int d) {
    if (d == 1) return a;
    else {
        long long int temp = product(d/2) % c;
        if (d%2)
            return temp * temp % c * a % c;
        else
            return temp * temp % c;
    }
}

int main() {
    long long int output = 1;

    cin >> a >>  b >> c;
    
    a %= c;

    output = product(b);

    cout << output << "\n";
}
