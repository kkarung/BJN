/////////////////////////
// 2022.09.06/ kkarung //
//  Divide and Conquer //
/////////////////////////
////////////////////////////// report ////////////////////////////////////
// 부분 배열이 아니라 전체 배열에서 최댓값이 있다 가정하고, 이 값을 구하는 방법을 생각해보자
// 무조건 가운데에 위치한 element는 포함된다. 이를 왼쪽으로, 또는 오른쪽으로 greedy하게 끝까지 이동하면
// 전체 배열에서의 최댓값을 찾을 수 있다.
// 이제 Divide and Conquer 방식을 이용하여 왼쪽 절반에서 최댓값을 찾고, 오른쪽 절반에서도 똑같이 (이하 생략)

#include <iostream>
using namespace std;

int a[100000] = {0};

// 현재 배열에서 최댓값을 찾는 함수
long long int calArray (int i, int j) {
    int mid = (i+j)/2;
    int left = mid-1, right = mid+1; // greedy하게 이동할 후보
    int minA = a[mid];
    long long int sum = a[mid], maxA = minA*sum;

    while (j-i >= right-left) { // 배열 횟수만큼 반복함
        if (a[left]<=a[right]) {
            sum += a[right]; minA = min(minA, a[right]); right++;
        }
        else if (a[left]>a[right]){
            sum += a[left]; minA = min(minA, a[left]); left--;
        }
        maxA = max(maxA, sum*minA);
    }

    return maxA;
}

long long int maxArray (int i, int j) {
    long long int retn;
    if (i==j) return calArray(i, j);
    retn = max(maxArray(i, (i+j)/2), maxArray((i+j)/2+1, j));
    retn = max(retn, calArray(i, j));

    return retn;
}

int main() {
    int n;

    cin >> n;

    for (int i=0; i<n; i++)
        cin >> a[i];
    
    cout << maxArray(0, n) << "\n";

}
