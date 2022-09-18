//////////////////////////
// 2022.09.18 / kkarung //
//    binary search     //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 블루레이가 n개 있을 때, 블루레이 크기는 low: M이 N과 같을 때 => (가장 큰 영상),
// high: M=1이라 모든 영상을 한 블루레이에 담을 때 => (영상 크기의 합)
// 블루레이 크기는 최소한 (영상 평균 크기)보다는 클 것이므로 MAX((가장 큰 영상), (영상 평균 크기))가 최소 범위(low)가 된다
// 이제 이분 탐색을 이용하여 최소 블루레이 크기를 찾는다 다만 최소 블루레이 크기를 찾는 것이므로 low가 답임을 명심해야한다

#include <iostream>
using namespace std;
#define MAXN 100001

int main() {
    int n, m, maxLec = 0;
    long long int low, high, mid, sum = 0;
    int lecture[MAXN] = {0};
    long long int partialSum[MAXN] = {0};

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> lecture[i];
        maxLec = lecture[i] > maxLec ? lecture[i] : maxLec;
        sum += lecture[i];
    }

    low = maxLec > sum/m ? maxLec : sum/m;
    high = sum;
    
    while (low <= high) {
        int num = 0;
        mid = (low+high)/2;

        for (int i=0; i<n; i++) {
            if (partialSum[num]+lecture[i] > mid) partialSum[++num] = lecture[i];
            else partialSum[num] += lecture[i];
        }

        if (!partialSum[num]) num++;
        
        if (m >= num+1) high = mid-1;
        else low = mid+1;

        while (num >= 0) partialSum[num--] = 0;
    }

    cout << low << "\n";

}
