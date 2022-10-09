//////////////////////////
// 2022.10.09 / kkarung //
//    Tree traversal    //
//////////////////////////
///////////////////////// report ///////////////////////////////
// 기본적인 preorder, inorder, postorder 구현 문제
// children[i][0]은 i번째 알파벳의 왼쪽노드,

#include <iostream>
using namespace std;

char children[27][2];

void preorder(int root) {
	cout << (char)(root+'A');
	if (children[root][0]!='.') preorder(children[root][0]-'A');
	if (children[root][1]!='.') preorder(children[root][1]-'A');
}

void inorder(int root) {
	if (children[root][0]!='.') inorder(children[root][0]-'A');
	cout << (char)(root+'A');
	if (children[root][1]!='.') inorder(children[root][1]-'A');
}

void postorder(int root) {
	if (children[root][0]!='.') postorder(children[root][0]-'A');
	if (children[root][1]!='.') postorder(children[root][1]-'A');
	cout << (char)(root+'A');
}

int main() {
	int N;
	cin >> N;
	
	for (int i=0; i<N; i++) {
		char node, lc, rc;
		cin >> node;
		cin >> children[node-'A'][0] >> children[node-'A'][1];
	}
	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';
}
