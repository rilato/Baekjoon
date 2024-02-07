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


// 다른 풀이

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
		arr[product % 10]++; // 10으로 나눈 나머지를 통해 인덱스 값 더하기
		product /= 10;		 // 값을 10으로 나눠주기
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
}