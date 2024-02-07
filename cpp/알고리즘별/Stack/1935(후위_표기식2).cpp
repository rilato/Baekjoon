#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	double num, firstNum, secondNum;
	string S;
	map <char, double> m;
	stack <double> st;
	double ans = 0;

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> num;

		// �ƽ�Ű �ڵ� ǥ�� ���� map�� �ش� ���� ����
		m['A' + i] = num;
	}

	for (int i = 0; i < S.size(); i++) {
		// �������� ��� �Ʒ��� ������ ��ħ. ��, ����� ������� ������ �߿��ϹǷ�, ���ÿ��� ������ ������ ����!
		if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/') {
			secondNum = st.top();
			st.pop();
			firstNum = st.top();
			st.pop();

			if (S[i] == '+')
				st.push(firstNum + secondNum);
			else if (S[i] == '-')
				st.push(firstNum - secondNum);
			else if (S[i] == '*')
				st.push(firstNum * secondNum);
			else if (S[i] == '/')
				st.push(firstNum / secondNum);
		}
		else {
			// �����ڰ� �ƴ� ��쿡�� ���ڸ� ���ÿ� �ֱ�
			st.push(m[S[i]]);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();

	return 0;
}