// https://tooo1.tistory.com/146
// bool�� �̿��Ѵ�.
// -�� �� �� �����ϴ� ����, +�� �������� ��ȣ�� ���� -�� ó���ǵ��� �Ѵ�.
// ��, -�� �� �� ������ �� ���� ���ڴ� ������ ���ش�.


#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	string temp = "";
	int result = 0;
	bool isMinus = false;

	cin >> S;

	// �� ������ ���� NULL���� �޴´�.
	for (int i = 0; i <= S.size(); i++) {
		// ���⼭ �� ������ ������ NULL�� ���ؼ��� ó���Ѵ�.
		// �׷��� �� ������ ����� temp ���� ���� ����� ����������.
		if (S[i] == '+' || S[i] == '-' || S[i] == '\0') {
			// ������ ���� �������� ��� -�� �Ѵ�.
			if (isMinus) {
				result -= stoi(temp);
			}
			// ������ ���� ���� ���·� ������ ��� +�� �Ѵ�.
			else {
				result += stoi(temp);
			}
			temp = "";
			// - ��ȣ�� ���� ��� üũ
			if (S[i] == '-') {
				isMinus = true;
			}
		}
		// temp ������ �� ����
		else {
			temp += S[i];
		}
	}

	cout << result;
}