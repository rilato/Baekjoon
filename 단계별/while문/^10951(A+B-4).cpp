//�� ������ Ǯ�� ���ؼ� EOF(End Of File)�� ���� �� �ʿ䰡 �ִ�.
//EOF(End Of File)�� ������ ���� �˸��� �Լ��� - 1�� ���� ������, �ܼ� â������ Ctrl + Z�� EOF�� �ǹ��Ѵ�.
//C++������ cin.eof()�Լ��� boolŸ���� ������ EOF�� ������ true������ �ٲ�� �ȴ�.

#include <iostream>

using namespace std;

int main()
{
	int A, B;

	while (1) {
		cin >> A >> B;

		if (cin.eof() == 1) // EOF�� ���̸� Ż��
			break;

		cout << A + B << '\n';
	}
}



// �ٸ� ���

#include <iostream>

using namespace std;

int main()
{
	int A, B;

	while (cin >> A >> B) {
		cout << A + B << '\n';
	}
}