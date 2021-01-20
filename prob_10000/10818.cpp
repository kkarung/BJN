// 460ms로 느린 속도로 풀었음
#include <iostream>
using namespace std;

int main() {
    int n, z, max=-1000001, min=1000001;
    cin >> n;
    while (n-->0) {
        cin >> z;
        max = (z > max) ? z : max;
        min = (z < min) ? z : min;
    }
    cout << min << " " << max;
}
