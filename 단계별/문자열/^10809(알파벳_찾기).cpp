//Ư�� ���ڸ� ã�� �� ���� find

//string str = "�ƹ� ���ڿ�";
//str.find("���ϴ� ���ڿ�", startIndex);

//str���� ���ϴ� ���ڰ� ������ str���� �ش��ϴ� ��ġ�� ��ȯ���ָ� ���� ������ -1�� �����ϴ� ����.



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