#include<iostream>
#include<string>
#include<queue>

//���� ģ��
//ť

using namespace std;
int n;
int k;
string f;
int friends[300000];
queue <int> q[21];//�̸��� ���� ��ŭ�� ť �迭 ����

long long solution() {
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> f;
		friends[i] = f.length();

		if (q[friends[i]].empty()) {
			q[friends[i]].push(i);
		}//��������� ť�� ����
		else {
			while (i - q[friends[i]].front() > k) {
				q[friends[i]].pop();
				if (q[friends[i]].empty()) {
					break;
				}//���� ������ ģ���� ť���� ģ���� ���� ģ���� �ƴϸ� pop
			}
			ans += q[friends[i]].size();//���� ģ���� �������� ���� ģ���� ���� �߰�
			q[friends[i]].push(i);//���� ������ ģ���� ť�� ����
		}
	}
	return ans ;
}//�Է°��� �����鼭 �̸��� ���̸� ť�� �ε����� ����, ���̿� �ش��ϴ� �ε����� ť�� ������ �־��ش�.
int main() {
	cin >> n;
	cin >> k;

	cout << solution();

	return 0;
}

