//////////////////////////
// 2022.09.19 / kkarung //
//        array         //
//////////////////////////
///////////////////////// report ///////////////////////////////
// input엔 문제에서 요구하는 숫자들을 저장하고, queue엔 1~N까지 숫자를 저장한다
// 문제에서 요구하는 숫자가 현재 위치하고 있는 position에서 얼마나 떨어졌는지 계산한다

#include <iostream>
#include <list>
using namespace std;
#define MAXN 51

int main() {
    int n, m, num, pos = 0, output = 0;
    int input[MAXN] = {0}, queue[MAXN] = {0};

    cin >> n >> m;
    for (int i=0; i<m; i++) cin >> input[i];
    for (int i=0; i<n; i++) queue[i]=i+1;

    for (int i=0, j=0; i<m; i++, pos++, num=0) {
        if (input[i] > queue[pos]) {
            for (j=pos; queue[j] < input[i]; j++, num++) ;
        }
        else if (input[i] < queue[pos]) {
            for (j=pos; queue[j] > input[i]; j--, num++) ;
        }
        output += num > n-num ? n-num : num; // 거리의 최솟값
        pos = j-1; // 찾은 숫자는 queue에서 제거하므로 인덱스도 왼쪽으로 한 칸 이동

        // 삭제
        for (int k=j; k<n-1; k++) { queue[k]=queue[k+1];}
        queue[n--] = 0;
    }

    cout << output;
}
