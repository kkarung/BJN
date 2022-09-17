//////////////////////////
// 2022.09.17 / kkarung //
//    binary search     //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 2805와 굉장히 유사한 문제
// 선택할 수 있는 예산 범위는 0 ~ (최대 요구 예산), 이에 따른 총 필요한 예산 범위는 0 ~ (계산) 이렇게 된다
// left: 0, right: (최대 요구 예산)으로 두고 이분탐색을 사용하자
// while문에서 left, right 범위 취급에 주의할 것
// 시간 복잡도는 O(nlogmaxBudget)이므로 제한 조건에 만족

#include <iostream>
using namespace std;
#define MAXN 100001

int main() {
    int n, m, left = 0, right = 0, mid;
    int budget[MAXN];

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> budget[i];
        if (budget[i] > right) right = budget[i];
    }
    cin >> m;

    while (left <= right) {
        long long int totalBudget = 0;
        mid = (left+right)/2;
        
        for (int i=0; i<n; i++)
            totalBudget += (budget[i] > mid ? mid : budget[i]);
            
        if (totalBudget <= m) left = mid+1;
        else right = mid-1;
    }

    cout << right << "\n";
}
