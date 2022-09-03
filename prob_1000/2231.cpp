/////////////////////////
// 2022.09.03 / kkarung /
//     brute force     //
/////////////////////////
///////////////////////// report ///////////////////////////////
// 분해합 N(M과 M을 이루는 각 자리 수의 합) > M 이므로 0~N-1까지 for문으로 분해합 계산
// 분해합은 M을 string > char* > int로 쪼개서 더하면 간단함
// 시간 제한은 2초이고, N의 개수는 10의 6승이므로 이중 for문이 안 될 것 같지만
// 두 번째 for문은 N의 자릿수만큼 반복되고, N의 자릿수는 최대 7자리이므로
// 시간 복잡도는 log(n)으로 봐도 무방하다
// 형 변환 참고: https://velog.io/@neity16/C-%ED%98%95-%EB%B3%80%ED%99%98-%EC%A0%95%EB%A6%AC

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int N, sum, M;
    string num_str;

    cin >> N;

    for (M=0; M<N; M++, sum=0) {
        num_str = to_string(M);
        char const* num_char = num_str.c_str();

        for (int j=0; j<strlen(num_char); j++)
            sum += num_char[j]-'0';

        if (sum+M == N) break;
    }

    if (M==N) M=0;

    cout << M << '\n';
}
