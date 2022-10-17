#include <iostream>
using namespace std;

int main() {
    int n, sum=0;
    char num[100];
    cin >> n >> num;
  
    while (n--) {
        sum += num[n]-'0';
    }
    cout << sum;
}
