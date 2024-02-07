//특정 문자를 찾을 때 쓰는 find

//string str = "아무 문자열";
//str.find("원하는 문자열", startIndex);

//str에서 원하는 문자가 있으면 str에서 해당하는 위치를 반환해주며 없을 때에는 -1을 리턴하는 구조.



#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	cin >> word;

	for (int i = 0; i < alphabet.size(); i++) {
		cout << (int)word.find(alphabet[i]) << " ";
	}
}