/////////////////////////
// 2022.09.04 / kkarung /
//     brute force     //
/////////////////////////
///////////////////////// report ///////////////////////////////
// n = 44일 때 삼각수 = 990이므로 44의 3승 = 약 85000은 충분히 연산 가능함
// 따라서 log(n^3) 방식으로 계산

#include <iostream>
#include <algorithm>
using namespace std;

bool isEureka(int, int[]);

int main() {
    int n, num;
    int triangl[44] = {0};

    cin >> n;

    for (int i=1; i<=44; i++)
        triangl[i-1] = i*(i+1)/2;

    for (int i=0; i<n; i++){
        cin >> num;
        if (isEureka(num, triangl))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

bool isEureka (int num, int triangl[]) {

    for (int i=0; i<44; i++) {
        for (int j=0; j<44; j++) {
            for (int k=0; k<44; k++) {
                if (num==(triangl[i]+triangl[j]+triangl[k]))
                    return true;
            }
        }
    }
    
    return false;
}
