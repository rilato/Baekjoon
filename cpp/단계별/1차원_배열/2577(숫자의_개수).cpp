#include <iostream>
#include <string>

using namespace std;


int main()
{
	int A, B, C;
	int product;
	int arr[10] = { 0, };
	string pro;

	cin >> A >> B >> C;

	product = A * B * C;

	pro = to_string(product);

	for (int i = 0; i < size(pro); i++) {
		string character;
		int num;

		character = pro.substr(i, 1);

		num = stoi(character);

		++arr[num];
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
}


// �ٸ� Ǯ��

#include <iostream>

using namespace std;

int main()
{
	int A, B, C;
	int product;
	int arr[10] = { 0, };

	cin >> A >> B >> C;

	product = A * B * C;

	while (product != 0) {
		arr[product % 10]++; // 10���� ���� �������� ���� �ε��� �� ���ϱ�
		product /= 10;		 // ���� 10���� �����ֱ�
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
}