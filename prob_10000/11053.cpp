/////////////////////////
// 2021.02.10 / kkarung /
//    DP / Bottom-up   //
/////////////////////////
///////////////////////// report ///////////////////////////////
// 용어 설명: DP[i]는 i번째에서 가장 긴 증가하는 부분 수열
// 용어 설명: term[i]는 i번째 원소
// 용어 설명: length는 가장 긴 증가하는 부분 수열의 길이
// 계산: i번째에서 가장 긴 부분 수열을 0 ~ (i-1)번째까지 비교하면서 찾아보기
// - i번째 원소가 j(<i인 원소)번째 원소보다 클 때, DP[i]가 DP[j]+1 보다 크면 DP[i] 갱신
// DP[i]를 찾고 나면 length 갱신

#include <iostream>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

int main() {
    int n, length = 0;
    int term[1001], DP[1001] = {0};
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> term[i];
        DP[i] = 1;
        for (int j=1; j<i; j++)
            if (term[i] > term[j])
                DP[i] = MAX(DP[i], DP[j]+1);
        length = MAX(length, DP[i]);
    }
    cout << length << "\n";
}
