// string�� long long���� ��ȯ�ϱ� ���� stoll�� ����.

#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2, s3, s4;
	string temp1, temp2;
	long long ans;

	cin >> s1 >> s2 >> s3 >> s4;

	temp1 = s1 + s2;
	temp2 = s3 + s4;

	// stoll �� string�� long long���� ��ȯ
	ans = stoll(temp1) + stoll(temp2);

	cout << ans;
}