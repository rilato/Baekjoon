#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b;
	int num1, num2;

	cin >> a >> b;

	num1 = stoi(a);

	for (int i = 2; i >= 0; i--) {
		num2 = stoi(b.substr(i, 1));
		cout << num1 * num2 << endl;
	}

	num2 = stoi(b);
	cout << num1 * num2;
}



// �ٸ� Ǯ��

#include <iostream>
using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;
	cout << a * (b % 10) << '\n';    //3���� �ش��ϴ� �ڵ�
	cout << a * ((b / 10) % 10) << '\n';  //4���� �ش��ϴ� �ڵ�
	cout << a * (b / 100) << '\n';   //5���� �ش��ϴ� �ڵ�
	cout << a * b << '\n';            //6���� �ش��ϴ� �ڵ�

	return 0;
}