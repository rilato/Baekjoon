#include <iostream>

using namespace std;

int main()
{
	// 1 2 3 4 5	/ �и�
	// 
	// 1 2 4 7 11	/ �� ��, input ��
	//  1 2 3 4		/ d

	int input, numerator;
	int sum = 0;
	int d = 1;

	cin >> input;

	while (1) {
		if (sum < input && input <= sum + d)
			break;
		sum += d;
		++d;
	}

	numerator = input - sum;

	if (d % 2 == 0)
		cout << numerator << "/" << d + 1 - numerator;
	else
		cout << d + 1 - numerator << "/" << numerator;
}


// �ٸ� Ǯ��

//i��° �밢������ i���� ���Ұ� �����Ƿ�,
//N�� ���° �밢���� �ִ��� �ľ��ϱ� ����
//i�� ���������� ������Ű�� ���ݴϴ�.
//N�� i���� �۾��� ��� �ش� i��° �밢���� N��° ���Ұ� �����մϴ�.

#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int i = 1;

	while (N > i) {
		N -= i;
		i++;
	}

	if (i % 2 == 1)
		cout << i + 1 - N << '/' << N << endl;
	else
		cout << N << '/' << i + 1 - N << endl;
}