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



// 다른 풀이

#include <iostream>
using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;
	cout << a * (b % 10) << '\n';    //3번에 해당하는 코드
	cout << a * ((b / 10) % 10) << '\n';  //4번에 해당하는 코드
	cout << a * (b / 100) << '\n';   //5번에 해당하는 코드
	cout << a * b << '\n';            //6번에 해당하는 코드

	return 0;
}