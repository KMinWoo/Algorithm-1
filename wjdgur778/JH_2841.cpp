#include<iostream>
#include<stack>
using namespace std;

//�ܰ����� ��Ÿ ���� 
//���� 
int n;
int p;

int solution() {

	stack <int> s[6];
	int a;
	int b;
	int cnt = 0;

	for (int i = 0; i < n; i++) {

		cin >> a;
		cin >> b;
		a -= 1;

		if (s[a].empty()) {
			s[a].push(b);
			cnt++;
			continue;
		}//��������� ���ؿ� �ְ� ī��Ʈ
		else
		{
			if (s[a].top() < b) {
				s[a].push(b);
				cnt++;
			}//�������ϴ� ���� ������ ������ ũ�� Ǫ��
			else if (s[a].top() == b) {
				continue;
			}//������ �ƹ��� ���� x
			else {
				while (!s[a].empty() && s[a].top() > b) {
					s[a].pop();
					cnt++;
				}
				if (!s[a].empty() && s[a].top() == b) {
					continue;
				}
				s[a].push(b);
				cnt++;
			}//���� ������ ������ ������ 
			 //Ŀ���� ���� ���� �ϸ鼭 ī��Ʈ
		}
	}//�Է��� �ϸ鼭 ��

	return cnt;
}

int main() {
	cin >> n;
	cin >> p;
	cout << solution();
	return 0;
}
