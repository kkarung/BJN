#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int j;
        for (j=0; j<n-i; j++) cout << " ";
        for (j=0; j<2*i-1; j++) cout << "*";
        if (i!=n) cout << " ";
        cout << "\n";
    }
}
