/////////////////////////
// 2022.09.05/ kkarung //
//  greedy algorithm   //
/////////////////////////
/////////////////////////// report /////////////////////////////////
// greedy algorithm 연습하려고 푼 문제라서 이미 어떤 방법을 써야할 지 알고 있었음
// 그 순간에 최선의 선택을 하면 (수리해야할 곳-0.5)~(수리해야할 곳-0.5+L)만큼
// 테이프를 붙이면 된다. 이 때 이전 테이프가 (수리해야할 곳+0.5)까지 붙여 있다면
// 굳이 붙일 필요 없다

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, l;
    float repairedDx = 0;
    int output = 0;
    int input[1000] = {0};

    cin >> n >> l;

    for (int i=0; i<1000; i++)
        if (i<n) cin >> input[i];

    sort(input, input+n);
    
    for (int i=0; i<n; i++) {
        if (repairedDx>=input[i]+0.5) continue;
        else {
            repairedDx = input[i]-0.5+l;
            output++;
        }
    }

    cout << output << "\n";
}
