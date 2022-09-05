/////////////////////////
// 2022.09.05/ kkarung //
//  greedy algorithm   //
/////////////////////////
/////////////////////// report /////////////////////////////
// 그냥 예제의 경우에서 어떻게 구해야 할 지 식 생각하고, 그걸 똑같이 일반화함

#include <iostream>
using namespace std;

int main() {
    int l, p, v, i=0;

    while (cin >> l >> p >> v) {
        if (!(l+p+v)) break;
        cout << "Case " << ++i <<  ": " << (v/p)*l+min(l, v%p) << "\n";
    }
}
