/////////////////////////////
//   2021.02.05 / kkarung  //
//      DP / Bottom-up     //
// DP[1]~ P[10]까지 전부 구함 //
/////////////////////////////

#include <iostream>
using namespace std;

int main() {
    int t, n;
    int DP[11] = {0};
    DP[1] = 1; DP[2] = 2; DP[3]=4;
    cin >> t;
    for (int i=4; i<11; i++)
        DP[i] = DP[i-1]+DP[i-2]+DP[i-3];

    while (t-->0) {
        cin >> n;
        cout << DP[n] << "\n";
    }
}
