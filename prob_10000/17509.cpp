/////////////////////////
// 2022.09.05/ kkarung //
//  greedy algorithm   //
/////////////////////////
///////////////////////// report ///////////////////////////////
// penalty = T+20V일 때, 최소 penalty를 구하면 되는데 20V는 순서에 영향x이므로
// T가 최소가 되면 된다 그러려면 d가 작은 값을 최대한 반복해야 T가 최소가 된다
// 즉, greedy algorithm을 이용해야한다

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int d[11], v[11];
    int time = 0;
    int output = 0;

    for (int i=0; i<11; i++) {
        cin >> d[i];
        cin >> v[i];
    }
  
    sort(d, d+11);

    for (int i=0; i<11; i++) {
        time += d[i];
        output += time;
        output += v[i]*20;
    }

    cout << output << "\n";
}
