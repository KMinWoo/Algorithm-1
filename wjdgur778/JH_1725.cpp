#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
//������׷�
//����
//�ʺ� ���ϱⰡ �߿�
int n;
int histo[100002] = { -1 };
stack <int> s;
int solution() {
	int a = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		histo[i] = a;
	}

	int tmp = 0;
	int top;
	int i;
	s.push(0);

	for (i = 1; i <=n; i++) {
		int a;
		while (!s.empty() && histo[s.top()] > histo[i]) {
			top = s.top();
			s.pop();
			if (s.empty())a = i;
			else a=i-s.top()-1 ;//�ʺ�
			tmp = max(tmp, (histo[top]*a));//(�ʺ� * ����)
		                                   //���� :������ ž (������� ���� ū ��)
		}
		s.push(i);
	}

	return tmp;
}
int main() {
	cin >> n;
	cout << solution();
	return 0;
}


