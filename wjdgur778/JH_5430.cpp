#include<iostream>
#include<string>
#include<deque>
using namespace std;
//AC
//�� ���
int t;
int n;
deque <int> d;
bool flag = false;
int direction = 1;

void solution() {

	for (int i = 0; i < t; i++) {
		string func;
		int n;
		string arr;
		string a;
		direction = 1;
		cin >> func;
		cin >> n;
		cin >> arr;

		for (int i = 1; i < arr.length(); i++) {
			if (arr[i] != ','&&arr[i] != ']') {
				a += arr[i];
			}
			else if (n != 0 && (arr[i] == ',' || arr[i] == ']'))
			{
				int m;
				m = atoi(a.c_str());
				d.push_back(m);
				a.clear();
			}
		}//���� ���� �Է�
		for (int i = 0; i < func.length(); i++) {

			if (func[i] == 'R') {
				direction *= -1;
			}

			else {
				if (d.empty()) {
					flag = true;
					break;
				}
				else if (direction == 1) {
					d.pop_front();
				}
				else if (direction == -1) {
					d.pop_back();
				}
			}
		}//�Լ� ����(������ ���ؼ� r�̸� ������ȯ,d�� �׹��⿡�� ��
	
		if (flag) {
			cout << "error" ;
			flag = false;
		}//���� ��������� error���
		else {
			cout << '[';
			while (!d.empty()) {
				if (direction == 1) {
					cout << d.front();
					d.pop_front();
				}
				else if(direction == -1) {
					cout << d.back();
					d.pop_back();
				}
				if (d.empty()) {
					break;
				}
				cout << ',';
			}
			cout << ']';
		}
		if(i!=t-1)
		cout << endl;
		//��� �κ�
	}
}
int main()
{
	cin >> t;
	solution();


	return 0;
}