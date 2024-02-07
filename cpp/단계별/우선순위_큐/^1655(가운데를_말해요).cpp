// https://regularmember.tistory.com/142

// 1. �ּ� ���� ������ ��� �ִ� ������ ũ�����ϰ�
// 2. �ִ� ���� ũ�Ⱑ �ּ� ���� ũ�⺸�� 1 ũ�ų� ������ �����ϸ� ���� �ִ´�.
// 3. ���� �־��� �� �ִ� ���� �ּ� ���� top ���� ���ؼ� �ּ� ���� top���� �ִ� ���� top�� �� ũ�ٸ� ���� ��ȯ���ش�.
// �׷��� �ִ� ���� top���� �߰����� �ȴ�.


// �ð� �ʰ��� �� Ǯ��

// ���� ��� ���� ������ �߰����� ������־�� �ϱ� ������ �Ź� ������ �ؼ� ��� ���� ������ָ� �ð� �ʰ��� �߻��Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num, midIndex;
    int k = -1;
    vector <int> v;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;
        v.push_back(num);
        ++k;
        stable_sort(v.begin(), v.end());
        midIndex = k / 2;
        cout << v[midIndex] << '\n';
    }
}


// ���� Ǯ��

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input, num;
    priority_queue <int> maxHeap;
    priority_queue <int, vector<int>, greater<int>> minHeap;

    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> num;

        if (maxHeap.empty() || maxHeap.size() == minHeap.size())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int mintop = minHeap.top();
            int maxtop = maxHeap.top();
            minHeap.pop();
            maxHeap.pop();
            minHeap.push(maxtop);
            maxHeap.push(mintop);
        }

        cout << maxHeap.top() << '\n';
    }
}