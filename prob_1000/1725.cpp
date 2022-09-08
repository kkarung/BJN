/////////////////////////
// 2022.09.06/ kkarung //
//  Divide and Conquer //
/////////////////////////
///////////////////////// report ///////////////////////////////
// 2104번과 동일하니 패스
// 시간 초과 뜸 (right-left)*minH 부분에서 overflow라는데 아직 잘 모르겠음
// xxxxxxxxxxxxx

#include <iostream>
using namespace std;

int h[100000] = {0};

int histogram(int s, int e) {
    int maxSub;
    int mid = (s+e)/2, left = mid-1, right = mid+1;
    int maxV = h[mid];
    int minH = h[mid];

    if (s == e) return h[mid];
    
    maxSub = max(histogram(s, mid), histogram(mid+1, e));

    while (e>=right || s<=left) {
        if (h[left]<=h[right] || left < s) {
            minH = min(minH, h[right]);
            maxV = max(maxV, (right-left)*minH); right++;
        }
        else if (h[left]>=h[right] || right > e) {
            minH = min(minH, h[left]);
            maxV = max(maxV, (right-left)*minH); left--;
        }
    }

    return max(maxSub, maxV);

}

int main() {
    int n;

    cin >> n;

    for (int i=0; i<n; i++)
        cin >> h[i];
    
    cout << histogram(0, n-1) << "\n";

}
