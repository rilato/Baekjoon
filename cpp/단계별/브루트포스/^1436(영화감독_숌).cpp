// 666�� ���Ե� ���ڸ� "ã�ƾ�"�ϹǷ�, find() �Լ��� ����, 666�� ���ڿ��� ����� "666"�� ã�´�.
// find()�Լ��� ���ڿ��� ã�� ���� ���, string::npos�� ��ȯ�ϴµ�, �� ���� -1�� ����Ų��.

#include <iostream>
#include <string>

using namespace std;

int main() {
	int num;
	int count = 0;
	int six = 666;

	cin >> num;

	while (1) {
		string stringSix = to_string(six);

		// 666�̶�� ���ڿ��� ���Ե��ִ� ��� find �Լ��� 0, 1, 2... ���� ���ڸ� ��ȯ�Ѵ�.
		// 666�̶�� ���ڿ��� ���ԵǾ����� ���� ��� find �Լ��� string::npos (-1)�� ��ȯ�Ѵ�.
		if (stringSix.find("666") != -1)
			++count;

		if (count == num)
			break;

		six += 1;
	}

	cout << six;
}