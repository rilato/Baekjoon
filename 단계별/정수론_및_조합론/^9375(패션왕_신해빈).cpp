// �������� �ǻ� ������ ���� ������ ���� �߿��ϴ�.
// �� �ǻ������� + 1 �԰��� ���� �ڿ� ���� ���� ������ - 1�� ���� ���� �����̴�.

// ���� ������ 1�� ���� ������, ���Դ� ��츦 �����ϱ� ���� �����ִ� ���̴�.
// �������� 1�� �� ������, ���� �ϳ��� ���� ���� ��츦 �����ϱ� ���� ���̴�.


// ���� ������ ���� Ǯ��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector <string> v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input, num;
	string clothName, clothType;

	cin >> input;

	for (int i = 0; i < input; i++) {
		vector <string> v;

		cin >> num;

		for (int j = 0; j < num; j++) {
			cin >> clothName >> clothType;

			v.push_back(clothType);
		}

		print(v);
	}
}

void print(vector <string> v) {
	int k = 0;
	int arr[31] = { 0, };
	int product = 1;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == " ")
			continue;

		// ��ġ�� type�� ������, 1���� �����ϱ� 1�� ���ϰ� �����Ѵ�.
		arr[k]++;

		for (int j = i + 1; j < v.size(); j++) {
			// ������ ������ �ǳʶڴ�.
			if (v[j] == " ")
				continue;

			// ���� ���ڰ� ������ ���� �ڸ��� �������� �ٲ��ش�.
			if (v[i] == v[j]) {
				v[j] = " ";
				arr[k]++;
			}
		}

		product *= (arr[k] + 1);

		k++;
	}

	cout << product - 1 << '\n';
}


// �ٸ� ���� Ǯ��

#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int n;
	string catag, name;

	while (T--)
	{
		map<string, int> m;
		cin >> n;
		while (n--)
		{
			// name�� ��� x
			cin >> name >> catag;

			// find �Լ��� ã�� key���� ������ end �ּҸ� ����
			if (m.find(catag) == m.end())
				m.insert({ catag, 1 });

			else
				m[catag]++;
		}

		int ans = 1;

		// for������ auto i : m �������� ���� �Ǹ�, �����͸� ���� �ʾƵ� i ��ü�� �� ���� ����Ų��.
		for (auto i : m)
			ans *= (i.second + 1);

		cout << ans - 1 << '\n';
	}
}