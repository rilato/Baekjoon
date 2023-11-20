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

		// 아스키 코드 표에 의해 map에 해당 숫자 저장
		m['A' + i] = num;
	}

	for (int i = 0; i < S.size(); i++) {
		// 연산자인 경우 아래의 과정을 거침. 단, 빼기와 나누기는 순서가 중요하므로, 스택에서 빼내는 순서에 유의!
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
			// 연산자가 아닌 경우에만 숫자를 스택에 넣기
			st.push(m[S[i]]);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();

	return 0;
}