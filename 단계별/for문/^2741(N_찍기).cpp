// ios_base::sync_with_stdio(false); / cin.tie(NULL);�� �߰��ϸ� 4ms�� �ð� �̵��� �� �� �ִ�.
// ������ ���� �߿��� ���� endl�� ���� �ʰ� "\n"�� ���ִ� ���� ȹ������ �ӵ� ��� ������ �ȴٴ� ���̴�.


// 8ms
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, i;

	cin >> N;

	for (i = 1; i < N; i++) {
		cout << i << "\n";
	}
	cout << i;
}



// 12ms
#include <iostream>

using namespace std;

int main()
{
	int N, i;

	cin >> N;

	for (i = 1; i < N; i++) {
		cout << i << "\n";
	}
	cout << i;
}