// 입력 버퍼를 지워주는 동작을 해주는데 cin을 이용해 입력하면 입력버퍼에 입력한 값이 저장이되고 그 값이 변수에 저장이 되는 방식인데 '\n'을 버린다.
// 그렇다면 버린 '\n'은 삭제가 되는가? 아니다. 그대로 입력버퍼에 남아있게 된다.
// 그런데 getline은 입력 버퍼에 있는 내용을 저장하기 때문에 '\n'이 입력이 된다.
// 그렇기 때문에 원래 3번 입력을 해야하는데 2번을 입력해야하는 상황이 발생한다.
// 이를 방지하기 위해서 ignore을 사용한다.

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();		//입력 버퍼 지워주기(cin 사용 후 \n가 입력버퍼에 남아있어서 getline에서 입력 처리가 된다.)
	while (n--)
	{
		string arr;
		getline(cin, arr);		//띄어쓰기 포함한 문자열 입력
		arr += ' ';				//문장의 끝도 변화시키기 위함
		stack<char> s;

		for (char ch : arr)		//배열 arr의 값을 순차적으로 ch에 저장
		{
			if (ch == ' ')			//문장의 중간 혹은 끝
			{
				while (!s.empty())	//스택이 비워질 때까지
				{
					cout << s.top();//문자 출력
					s.pop();
				}
				cout << ch;		//띄어쓰기 출력
			}
			else				//띄어쓰기가 입력이 안될 때
				s.push(ch);
		}
	}
	return 0;
}