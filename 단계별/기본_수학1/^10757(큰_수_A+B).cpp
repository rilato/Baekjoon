// ���� ū ���� long long ���ε� ������ �� ����.
// ���� string�� ����Ѵ�.
// 
// string���� ���� num1�� num2�� �����´�.
// �� ���ڸ����� �ϳ��� ���Ѵ�. 10�� �Ѿ�� carry�� �߻��Ѵ�.
// ���� ���� �ٽ� ������ ���� ���� �����.

#include <iostream>
#include <string>

using namespace std;

void reverse(string& s);

int main() {
	string num1, num2, lower, higher;
	string ans;
	long long length;
	int carry = 0;
	int sum;

	cin >> num1 >> num2;

	reverse(num1);
	reverse(num2);

	if (num1.size() >= num2.size()) {
		length = num1.size() - num2.size();
		lower = num2;
		higher = num1;
	}
	else {
		length = num2.size() - num1.size();
		lower = num1;
		higher = num2;
	}

	for (int i = 0; i < lower.size(); i++) {
		sum = stoi(lower.substr(i, 1)) + stoi(higher.substr(i, 1)) + carry;

		if (sum >= 10) {
			carry = 1;
			ans += to_string(sum - 10);
		}

		else {
			carry = 0;
			ans += to_string(sum);
		}

		if (i == lower.size() - 1 && lower.size() == higher.size() && carry == 1)   // �������� ���� ���� 10�� �Ѿ �� carry�� �ݿ��ؾ� �Ѵ�.
			ans += to_string(carry);
	}

	for (int i = lower.size(); i < higher.size(); i++) {
		sum = stoi(higher.substr(i, 1)) + carry;

		if (sum >= 10) {
			carry = 1;
			ans += to_string(sum - 10);
		}

		else {
			carry = 0;
			ans += to_string(sum);
		}

		if (i == higher.size() - 1 && carry == 1)   // �������� ���� ���� 10�� �Ѿ �� carry�� �ݿ��ؾ� �Ѵ�.
			ans += to_string(carry);
	}

	reverse(ans);

	cout << ans;
}

void reverse(string& s) {			// ���� ������ �̿��Ͽ� ���� s�� �ٺ������� �ٲ��ش�.
	char temp;

	for (int i = 0; i < s.size() / 2; i++) {
		temp = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = temp;
	}
}



// �ٸ� Ǯ��

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, sum;
int num1[10001], num2[10001];
string s1, s2, tmp;
vector<int> ans;

int main()
{
	cin >> s1 >> s2;

	// �� �� ���� s1���� �����ϱ�
	if (s1.size() < s2.size())
	{
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}

	// num1, num2 �迭�� ����� ����
	for (int i = 0; i < s1.size(); i++)
		num1[i + 1] = s1[i] - '0';	// - '0'�� ���� ���ڸ� ���ڷ� ����

	for (int i = 0; i < s2.size(); i++)
		num2[i + 1 + (s1.size() - s2.size())] = s2[i] - '0';	// (s1.size()-s2.size())�� ���� num1�� num2�� ���� �� �ڸ����� ������

	// num�迭���� ���κк��� ������ �ϸ鼭 ans���Ϳ� �� ����
	for (int i = s1.size(); i > 0; i--)
	{
		sum = num1[i] + num2[i];
		if (sum >= 10)
		{
			num1[i - 1]++;	// ���ڸ��� carry��(1)�� ����
			sum -= 10;
		}
		ans.push_back(sum);
	}

	// �� ���ڸ��� ���
	if (num1[0] != 0) cout << 1;

	// ans���� �Ųٷ� ���
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}

}