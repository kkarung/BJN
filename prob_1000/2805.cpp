//////////////////////////
// 2022.09.17 / kkarung //
//    binary search     //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 해답이 될 수 있는 0 ~ 최대높이를 이분탐색함
// 높이 하나를 mid로 선택하여 그 경우 문제 조건을 만족할 수 있으면 mid ~ high, 조건을 만족하지 못하면 low ~ mid
// 이분탐색을 할 수 있는 이유는 절단기 높이가 0일 때부터 순차적으로 적어지기 때문에 정렬이 되어있다고 생각할 수 있기 때문이다
// 시간복잡도는 O(nlogmaxM)이고 n은 최대 10의 6승, maxM은 2의 31승이므로 시간 제한에 맞출 수 있다.
// 이해 안 되면 https://blog.naver.com/kks227/220777333252 참고

#include <iostream>
using namespace std;
#define MAXN 1000001

int main() {
    int tree[MAXN] = {0};
    int n, m, left = 0, right = 0, mid;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> tree[i];
        if (tree[i] > right) right = tree[i];
    }
    
    while (left+1 < right) {
        long long int treeLen = 0;
        mid = (left+right)/2;

        for (int i=0; i<n; i++)
            if (tree[i] > mid) treeLen += (tree[i]-mid);
            
        if (treeLen >= m) left = mid;
        else right = mid;
    }
    
    cout << left << "\n";
}
