// for���� �̿��Ͽ� ����� ���� ������, �ð��� ���� �ɸ��Ƿ� for���� ������� �ʴ� �������� �����Ѵ�.

#include <iostream>

using namespace std;

int main()
{
	long long fixedCost, variableCost, breakEvenPoint;

	cin >> fixedCost >> variableCost >> breakEvenPoint;

	if (variableCost >= breakEvenPoint)
		cout << -1;
	else
		cout << fixedCost / (breakEvenPoint - variableCost) + 1;
}