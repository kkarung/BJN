#include <iostream>
using namespace std;

struct member {
  int age;
  string name;
};

int main() {
  int N;
  cin >> N;
  member *input = new member[N];
  member *output = new member[N];
  int temp[201] = {0}; // 1부터 200까지이므로

  for (int i=0; i<N; i++) { 
    cin >> input[i].age >> input[i].name; // input할 배열 입력
    temp[input[i].age]++; // age의 개수 저장
  }

  for (int i=1; i<201; i++) // age의 개수 누적
    temp[i] += temp[i-1];

  for (int i=N-1; i>=0; i--) { // output에 input 마지막부터 저장
    temp[input[i].age]--;
    output[temp[input[i].age]].age = input[i].age;
    output[temp[input[i].age]].name = input[i].name;
  }

  for (int i=0; i<N; i++) {
    cout << output[i].age << " " << output[i].name << '\n'; // https://www.acmicpc.net/board/view/5096
  }

  delete[] input;
  delete[] output;

  return 0;
}
