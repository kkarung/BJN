/////////////////////////
// 2022.09.03 / kkarung /
//     brute force     //
/////////////////////////
///////////////////////// report ///////////////////////////////
// 전체 키를 더한 값에서 잉여로 추가된 두 명의 키 찾기
// surplus를 -100으로 두고 전체 키를 더함으로써 잉여 키를 찾을 수 있음
// 찾는 방법은 이중 for문 사용함 (최대 72번 수행하므로 시간복잡도 고려x)

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, surplus = -100;
    int input[9], not_output[2];

    for (int i=0; i<9; i++) {
        cin >> input[i];
        surplus += input[i];
    }

    sort(input, input+9);

    for (int i=0; i<8; i++) {
        for (int j=i; j<9; j++) {
            if (i!=j && (input[i]+input[j] == surplus)) {
                not_output[0] = i;
                not_output[1] = j;
            }
        }
    }

    for (int k=0; k<9; k++) {
        if (k!=not_output[0] && k!=not_output[1])
            cout << input[k] << '\n';
    }
}
