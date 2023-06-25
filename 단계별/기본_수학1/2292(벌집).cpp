// for문을 이용하여 계산할 수도 있지만, 시간이 오래 걸리므로 for문을 사용하지 않는 방향으로 생각한다.

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