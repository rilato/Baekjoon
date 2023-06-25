// ���ͽ�Ʈ�� �˰��� : https://wooono.tistory.com/397
// ���� Ǯ�� : https://wooono.tistory.com/398

#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000 // ���� ��忡�� �ش� �������� ��ΰ� ���� ����� ���
#define MAX_VERTEX 20001 // �ִ� vertex ����
#define MAX_EDGE 300001 // �ִ� edge ����

using namespace std;

int d[MAX_VERTEX]; // �ּ� ��� �迭
vector<pair<int, int> > edge[MAX_EDGE]; //���� ������ ���� Vector ����, index(MAX_EDGE �κ�) : ���� ��� / value : pair<���, ���� ���> ���

void dijkstra(int start_node);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, e, start_node;

    cin >> v >> e;      // ����� ������ ������ ���� �Է�

    cin >> start_node;    // ���� ��� �Է�

    // �ּ� ��� �迭 �ʱ�ȭ
    for (int i = 1; i <= v; i++) {
        d[i] = INF;
    }

    // ���� ����
    for (int i = 0; i < e; i++) {
        int start, end, cost;

        cin >> start >> end >> cost;        // ���� ���, ���� ���, ��� �Է�

        edge[start].push_back({ cost, end });        // ���� ��忡 ���� <���, ���� ���> ����
    }

    dijkstra(start_node);    // ���ͽ�Ʈ�� �Լ� ����

    // �ּ� ��� �迭 ���
    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << d[i] << "\n";
        }
    }

    return 0;

}

void dijkstra(int start_node) {
    d[start_node] = 0;    // ���� ��忡�� ���� ���� ���� ����� 0

    // ���� ������ � ���� �������� �ּ� ����� �����ϴ� ���� ����̸�,
    // pair<���, ���� ���> ������ �켱 ���� ť�̴�.
    priority_queue<pair<int, int> > pq;

    // ���� ��忡�� ���� ���� ���� ��ο� ����� pq �� ����
    pq.push({ 0, start_node });

    // pq �� ��� ��ε��� Ȯ���� ������ �ݺ�
    while (!pq.empty()) {
        // ������ �켱 ���� ť��, ù ��° ���� �������� ū ���� top �� ������ ���ĵǾ��ִ�.
        // ������, �ش� �˰��򿡼�, ��� ���� ����ȭ �� �� ù ��° ������ �����ϰ�, ���� ���� �� ��° ������ �����Ѵ�.
        // ����, ����� ���� ���� ���� top �� ������ ���ĵǾ��ִ�.
        // ��, ���� �ּ� ����� �����ϴ� ��κ��� Ȯ���ϰ� �ȴ�.

        // ���� ��忡�� � ���� �������� �ּ� ��θ� �����ϴ� pq �� top ����,
        // ���� ��带 ���� ���� �����Ѵ�.
        int current = pq.top().second;

        // ���� ��忡�� ���� �������� ����� �����Ѵ�.
        // ����� ����ȭ�Ǿ��ִ� �����̹Ƿ�, ���ȭ�ؼ� ����Ѵ�.
        int start_to_current_distance = -pq.top().first;

        // ���� ��δ� Ȯ�� �Ǿ����Ƿ�, �켱 ���� ť���� �����Ѵ�.
        pq.pop();

        // pq �� top ���� ����, ���� ������ ���� �������� ����
        // �ּ� ��� �迭�� �ִ�, ���� ������ ���� �������� ����� �������ν�,
        // pq �� top ���� ����, ���� ������ ���� �������� ����� �� ũ��
        // ���� �ش� ��θ� ���� ������ ������ Ȯ���� �ʿ䰡 �����Ƿ�, �� �̻� Ȯ������ ����
        if (d[current] < start_to_current_distance) {
            continue;
        }

        // ��� ���ǹ��� �ɸ��� �ʰ� ����ϸ�,
        // ���� ������ ���� �������� �ּ� ������� �̷���� �����̹Ƿ�, 
        // ���� ���� ���� ����� ������ ��� �˻��Ѵ�.
        for (int i = 0; i < edge[current].size(); i++) {
            // ���� ��� ����
            // ��, ���� ���� i ��°�� ������ ���
            int next = edge[current][i].second;

            // ���� ��忡�� ���� �������� ��� ����
            // ��, ���� ��忡�� ���� �������� ��� + ���� ��忡�� i ��°�� ������ �������� ���
            int start_to_next_distance = start_to_current_distance + edge[current][i].first;

            // ������, ���� ��忡�� ���� �������� �ּ� ��뺸��
            // ���Ӱ� �����, ���� ��忡�� ���� �������� ����� �� �۴ٸ�
            // �ּ� ����� ������Ʈ
            if (d[next] > start_to_next_distance) {
                d[next] = start_to_next_distance;

                // ����, ���ŵ� ��ΰ� �ּ� ������� �����ϱ� ����
                // �켱 ���� ť�� �ش� ��� ����
                pq.push({ -start_to_next_distance, next });
            }
        }
    }
}