#include<iostream>
#include <deque>
using namespace std;

//ī��2
//�� ���

deque <int> d;
int solution(int n) {
	for (int i = 1; i < n+1; i++) {
		d.push_back(i);
	}
	while (d.size() != 1) {
		int a;
		d.pop_front();
		//������
		a=d.front();
		d.pop_front();
		d.push_back(a);
	}
	return d.front();
}

int main() {
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}