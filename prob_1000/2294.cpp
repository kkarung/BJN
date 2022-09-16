//////////////////////////
// 2022.09.17 / kkarung //
//          DP          //
//////////////////////////
///////////////////////// report ///////////////////////////////
// DP[i]는 i원을 만드는 동전의 최소 개수
// k=23이고 2,7,9원이 있으면 min(DP[23-2],DP[23-7],DP[23-9])+1이 답
// leastCoin 함수에서 실현 가능성 있을 때는 1, 없을 때는 0을 return할 수 있게 하면
// 더 깔끔한 코드가 나올 것 같지만 일단은 pass

#include <iostream>
using namespace std;
#define MAXN 100
#define MAXK 100001

int n, k, mini = MAXK;
int coin[MAXN] = {0};
int dp[MAXK] = {0};

int leastCoin (int m) { // money
    int lsc = MAXK;
    
    if (m < 0) return MAXK;
    if (dp[m]) return dp[m];
    if (m < mini) return MAXK;
    else {
        for (int i=0; i<n; i++)
            lsc = min(lsc, leastCoin(m-coin[i])+1);
        dp[m] = lsc;
        return lsc;
    }
}

int main() {

    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> coin[i]; dp[coin[i]] = 1;
        mini = min(mini, coin[i]);
    }
    
    leastCoin(k);
    cout << ((dp[k] == MAXK) ? -1 : dp[k]);
}
