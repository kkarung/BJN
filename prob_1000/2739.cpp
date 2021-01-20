#include <iostream>
using namespace std;

int main() {
    int n, i=1;
    cin >> n;
    do {
        cout << n << " * " << i << " = " << n*i << "\n";
    } while (++i<10);
}
