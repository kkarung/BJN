/////////////////////////
// 2021.01.28 / kkarung /
//   DP / Bottom-up
/////////////////////////

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

////// 개션1: list[i] 초기화 부분을 빼자 //////
    
#include <iostream>
using namespace std;
int main() {
    int n;
    int list[1000001];
    list[1]=0;
    cin >> n;
    for (int i=4; i<=n; i++) {
        list[i] = list[i-1]+ 1;
        if (!(i%3)) list[i] = list[i/3]+1;
        if (!(i%2)) list[i] = (list[i] > list[i/2]+1 ? list[i/2]+1 : list[i]);
    }
    cout << list[n];
}

///// 개선2: Top-down 방식을 쓰자! //////
// 출처: https://www.acmicpc.net/source/6296573

#include<cstdio>
#include<algorithm>
int f(int n) {
	int a,b;
	if(n<2) 
		return 0;
	a=f(n/2)+n%2+1;
	b=f(n/3)+n%3+1;
	return std::min(a,b);
}
main(){
	int n;
	scanf("%d",&n);
	printf("%d",f(n));
}
