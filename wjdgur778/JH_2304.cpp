#include <iostream>
#include <algorithm>
using namespace std;

//â�� �ٰ���


int n;

int solution() {
	int max=0;
	int index;
	int size=0;
	pair <int, int> *pillar = new pair <int, int>[n];
	for (int i = 0; i < n; i++) {
		cin >> pillar[i].first >> pillar[i].second;
	}//��� �Է�
	sort(pillar, pillar + n);//�ε��� ����
	for (int i = 0; i < n; i++) {
		if (max < pillar[i].second) {
			max = pillar[i].second;
			index = i;
		}
	}//�Է�4
	int i=0;
	while (i < index) {
		for (int j = 1; i+j <= index; j++) {
			if (pillar[i].second <= pillar[i+j].second) {
				size += pillar[i].second *(pillar[i+j].first - pillar[i].first);
				i = i+j;
				break;
			}
		}
	}//���� �� ����� �������� ����
	i = n-1;
	while (i > index) {
		for (int j = 1; j <=n-index; j++) {
			if (pillar[i].second <= pillar[i-j].second) {
				size += pillar[i].second *(pillar[i].first - pillar[i-j].first);
				i =i-j ;
				break;
			}
		}
	}//���� �� ����� �������� ����
	return size + max;//�� + �� + �߰����(max)

}


int main() {
	cin >> n;//��� ����
	cout << solution();
	return 0;
}