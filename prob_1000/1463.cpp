#include <iostream>
using namespace std;
int main() {
    int n;
    int list[1000001];
    list[1]=0; list[2]=1; list[3]=1;
    cin >> n;
    for (int i=4; i<=n; i++) {
        list[i] = i; // 방법 1,2가 통하지 않을 때 list[i]는 쓰레기 값이므로(횟수는 아무리 작아도 i-1번)
        if (!(i%3)) list[i] = list[i/3]+1;
        if (!(i%2)) list[i] = (list[i] > list[i/2]+1 ? list[i/2]+1 : list[i]);
        list[i] = (list[i] > list[i-1]+1 ? list[i-1]+1 : list[i]);
    }
    cout << list[n];
}
