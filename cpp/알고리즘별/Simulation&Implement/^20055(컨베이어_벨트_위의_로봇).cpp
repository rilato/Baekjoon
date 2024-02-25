// 내리는 위치에 있는 로봇을 항상 내리는 작업을 수행하지 않으면, 내리는 위치에 있는 로봇이 내려가지 않고 물체를 옮기는 과정에서 무한 루프에 빠지게 된다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int cnt = 0;        // 내구도인 칸의 개수
int answer = 0;     // 단계 반복 횟수
vector <int> v;     // 내구도 배열
vector <bool> box;  // 물건 유무 여부

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    v.resize(2 * N);
    box.resize(N);  // 물건은 0부터 N - 1까지만 위치한다. 따라서 N 크기의 배열을 선언해준다.

    for (int i = 0; i < 2 * N; i++) {
        cin >> v[i];

        if (v[i] == 0) {
            cnt++;
        }
    }

    while (1) {
        //cout << "box : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << box[i] << ", ";
        //}
        //cout << "\n";

        //cout << "v : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << v[i] << ", ";
        //}
        //cout << "\n";


        // bool 배열과 v 배열 한 칸씩 돌리기
        bool tmp = box[N - 1];
        for (int i = N - 1; i >= 1; i--) {
            box[i] = box[i - 1];
        }
        box[0] = tmp;
        box[N - 1] = false; // 내리는 위치에 있는 로봇은 항상 내림

        int temp = v[2 * N - 1];
        for (int i = 2 * N - 1; i >= 1; i--) {
            v[i] = v[i - 1];
        }
        v[0] = temp;


        //cout << "rotation box : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << box[i] << ", ";
        //}
        //cout << "\n";

        //cout << "rotation v : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << v[i] << ", ";
        //}
        //cout << "\n";


        // 컨베이어벨트는 N - 1번째에서 내린다.
        // 현재 칸에 로봇이 있고, 앞에 로봇이 없고(앞의 bool 배열 값이 false) + 앞의 내구도가 1 이상이라면(앞의 v 배열 값이 1 이상) -> 이동
        for (int i = N - 2; i >= 0; i--) {
            if (box[i] && !box[i + 1] && v[i + 1] >= 1) {
                // 다음 칸으로 박스 옮기고, 다음 칸의 내구도 1 깎기
                box[i + 1] = true;
                box[i] = false;
                v[i + 1]--;

                // 내구도가 다 닳았다면 cnt++;
                if (v[i + 1] == 0) {
                    cnt++;
                }
            }
        }
        box[N - 1] = false; // 내리는 위치에 있는 로봇은 항상 내림


        // 현재 칸에 로봇이 없고, 내구도가 1 이상일 때 박스 올리기
        if (!box[0] && v[0] >= 1) {
            box[0] = true;
            v[0]--;

            // 내구도가 다 닳았다면 cnt++;
            if (v[0] == 0) {
                cnt++;
            }
        }

        //cout << "after input box : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << box[i] << ", ";
        //}
        //cout << "\n";

        //cout << "after input v : ";
        //for (int i = 0; i < 2 * N; i++) {
        //    cout << v[i] << ", ";
        //}
        //cout << "\n";

        answer++;

        // 내구도가 0인 칸이 K개라면 출력 후 종료
        if (cnt >= K) {
            cout << answer;
            break;
        }
    }

    return 0;
}