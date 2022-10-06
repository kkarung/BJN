/////////////////////////
// 2022.09.05/ kkarung //
//     brute force     //
//       비트마스크       //
/////////////////////////
//////////////////////////// report //////////////////////////////////
// brute force를 이용할 경우 각각의 정수가 들어갈 때, 안 들어갈 때 = (2의 n승)번 반복
// 최대, 2의 20승 = 10의 6승 반복하므로 brute force를 이용해도 괜찮다
// 각 정수의 flag가 1일 때 더하고, 0일 때 더하지 않는 방식을 이용한다
// 예시를 이용해서 이해하면 간단한데 예제 1을 보자
// -7 -3 -2 5 8 의 flag가 11101인 경우 5를 제외한 값을 더하고
// -7 -3 -2 5 8 의 flag가 00110인 경우 -2와 5를 더한다
// 즉, flag가 00000 ~ 11111인 경우를 다 해보면 되는데,
// 이 때 00000~11111를 이진수로 생각할 수 있다
// => 횟수(1~32)를 이진수로 만들고, 이진수를 flag로 생각하면 된다
// 참고: 이진수 변환 방법(https://velog.io/@sw801733/C-10%EC%A7%84%EC%88%98%EB%A5%BC-2%EC%A7%84%EC%88%98%EB%A1%9C-%EC%9D%B4%EC%A7%84%EB%B2%95-%EB%B3%80%ED%99%98)

#include <iostream>
#include <cmath>
#define OOB 1000001
using namespace std;

int main() {
    int n, s;
    int input[20];
    int output = 0;

    cin >> n >> s;

    for (int i=0; i<20; i++) {
        if (i<n) cin >> input[i];
        else input[i] = OOB;
    }

    for (int i=1; i<pow(2, n); i++) {
        int temp_sum = 0;
        for (int j=0; j<n; j++) { // n자리 이진수
            int bit = (i >> j) & 1;
            temp_sum += (bit==1) ? input[j] : 0;
        }
        if (temp_sum == s) output++;
    }

    cout << output << "\n";

}
