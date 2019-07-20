#include<iostream>
#include<string>
#include<stack>
using namespace std;

//���������
//�����̿�
//

string s;
string ans;
stack <char> stck;
string solution() {

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '*'&&s[i] != '/'&&s[i] != '+'&&s[i] != '-'&&s[i] != '('&&s[i] != ')') {
			ans += s[i];
		}
		else {
			if (stck.empty()) {
				stck.push(s[i]);
			}
			else {
				switch (s[i])

				{
				case '(':
					stck.push(s[i]);
					break;
				case ')':
					while (stck.top() != '(') {
						ans += stck.top();
						stck.pop();
					}
					stck.pop();
					break;
				case '+':
				case '-':
					while (!stck.empty() && (stck.top() != '(')) {
						ans += stck.top();
						stck.pop();
					}
					stck.push(s[i]);
					break;
				case '*':
				case'/':
					while (!stck.empty() && (stck.top() == '/' || stck.top() == '*')) {
						ans += stck.top();
						stck.pop();
					}
					stck.push(s[i]);
					break;
				}
			}
		}
	}//�����ڵ��� ���ÿ� �־�鼭 Ǯ��
	 //�������� �켱������ ���� ���þ��� �����ڰ� ������ �����ں��� �켱������ ������ ������ ���ڿ��� ������.
	while (!stck.empty()) {
		ans += stck.top(); stck.pop();
	}
	return ans;
}

int main() {
	cin >> s;
	cout << solution();
	return 0;
}