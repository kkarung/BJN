#include <iostream>
using namespace std;

int main() {
    int month[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int x, y, i=0;
    cin >> x >> y;
    do {
        y += month[i];
    } while (++i<x);
    cout << day[y%7];
}
