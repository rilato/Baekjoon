// https://deeepbreathing.tistory.com/28
// pair�� ������ ������.
// ��� �� �� sort�� ���� ���Ŀ��� : ù��° ���� ����, ù��°�� ������ �ι�°���ڷ� �Ǵ�

#include <iostream>
#include <queue>

using namespace std;

// second�� �������� ���� ������ greater<pair<int,int>>�� �κп��� ������������ �����ϴµ�,
// �̶� first -> second������ ���Ͽ� �������ֱ� �����̴�.
// �״ϱ� ���� 1,-1�� �Էµ� �� 0�� �ԷµǾ��ٸ�
// ������ ���� 1,1�� �� ���̰�, ���� ���� �����Ƿ� second������ ���ϰ� �Ǿ� -1�� ���� ��µ� ���̴�.

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void priorityQueue(int num);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        priorityQueue(num);
    }
}

void priorityQueue(int num) {
    if (!num) {
        if (pq.empty())
            cout << '0' << '\n';

        else {
            cout << pq.top().second << '\n';
            pq.pop();
        }
    }

    if (num)
        pq.push({ abs(num), num });
}