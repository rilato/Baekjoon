// ����� �������� �¿찡 ��Ī�� ���� �Ӹ���Ҽ���� �Ѵ�.

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num;
	int len = 0;

	while (1) {
		bool check = true;

		cin >> num;

		if (num == "0")
			break;

		len = num.size();

		for (int i = 0; i < len / 2; i++) {
			// �� ���ʺ��� ���ʴ���� ���ڿ� �� ���� ���ں��� ���ʴ���� ���� ��
			if (num[i] != num[len - i - 1]) {
				check = false;
				break;
			}
		}

		if (check)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}