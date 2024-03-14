#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, K, Row, Col, L, X;
string C;
int Time = 0;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
vector <vector <int>> v;
vector <vector <bool>> snake;
vector <pair <int, string>> turn;
vector <pair <pair <int, int>, int>> tailturn;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    v.resize(N + 1, vector <int>(N + 1));
    snake.resize(N + 1, vector <bool>(N + 1));

    // 사과 자리 입력
    for (int i = 0; i < K; i++) {
        cin >> Row >> Col;

        v[Row][Col] = -1;
    }

    cin >> L;

    for (int i = 0; i < L; i++) {
        cin >> X >> C;

        turn.push_back({ X, C });
    }

    // turn 배열의 idx
    int headj = 0;
    int tailj = 0;
    // row, col, dir (dir => 0 : 동, 1 : 서, 2 : 남, 3 : 북)
    queue <pair <pair <int, int>, int>> head;
    queue <pair <pair <int, int>, int>> tail;
    head.push({ { 1, 1 }, 0 });
    tail.push({ { 1, 1 }, 0 });

    while (!head.empty()) {
        int headr = head.front().first.first;
        int headc = head.front().first.second;
        int headd = head.front().second;
        int tailr = tail.front().first.first;
        int tailc = tail.front().first.second;
        int taild = tail.front().second;
        bool apple = false;

        head.pop();
        tail.pop();

        // 사과 여부
        if (v[headr][headc] == -1) {
            apple = true;
            // 사과를 먹었으니 사과 없애기
            v[headr][headc] = 0;
        }

        // 머리
        if (headj < turn.size() && turn[headj].first == Time) {
            // 우측으로 도는 경우
            if (turn[headj].second == "D") {
                if (headd == 0) {
                    headd = 2;
                }
                else if (headd == 1) {
                    headd = 3;
                }
                else if (headd == 2) {
                    headd = 1;
                }
                else {
                    headd = 0;
                }

                // 도는 경우, 꼬리에도 돌았다는 내용을 저장
                tailturn.push_back({ { headr, headc }, headd });
            }
            // 좌측으로 도는 경우
            else {
                if (headd == 0) {
                    headd = 3;
                }
                else if (headd == 1) {
                    headd = 2;
                }
                else if (headd == 2) {
                    headd = 0;
                }
                else {
                    headd = 1;
                }

                // 도는 경우, 꼬리에도 돌았다는 내용을 저장
                tailturn.push_back({ { headr, headc }, headd });
            }

            headj++;
        }

        Time++;

        // 꼬리 방향 전환 시, 꼬리의 방향인 taild 바꿔주기
        if (tailj < tailturn.size() && tailturn[tailj].first.first == tailr && tailturn[tailj].first.second == tailc) {
            taild = tailturn[tailj].second;
            
            tailj++;
        }

        if (headd == 0) {
            // 동으로 갔을 때, 범위를 넘거나, 내 몸통을 지나는 경우
            if (headc + 1 > N || snake[headr][headc + 1]) {
                cout << Time;
                break;
            }

            head.push({ { headr, headc + 1 }, headd });

            snake[headr][headc + 1] = true;
        }
        else if (headd == 1) {
            // 서로 갔을 때, 범위를 넘거나, 내 몸통을 지나는 경우
            if (headc - 1 < 1 || snake[headr][headc - 1]) {
                cout << Time;
                break;
            }

            head.push({ { headr, headc - 1 }, headd });

            snake[headr][headc - 1] = true;
        }
        else if (headd == 2) {
            // 남으로 갔을 때, 범위를 넘거나, 내 몸통을 지나는 경우
            if (headr + 1 > N || snake[headr + 1][headc]) {
                cout << Time;
                break;
            }

            head.push({ { headr + 1, headc }, headd });

            snake[headr + 1][headc] = true;
        }
        else if (headd == 3) {
            // 북으로 갔을 때, 범위를 넘거나, 내 몸통을 지나는 경우
            if (headr - 1 < 1 || snake[headr - 1][headc]) {
                cout << Time;
                break;
            }

            head.push({ { headr - 1, headc }, headd });

            snake[headr - 1][headc] = true;
        }

        // 사과 안먹은 경우
        if (!apple) {
            snake[tailr][tailc] = false;

            if (taild == 0) {
                tail.push({ { tailr, tailc + 1 }, taild });
            }
            else if (taild == 1) {
                tail.push({ { tailr, tailc - 1 }, taild });
            }
            else if (taild == 2) {
                tail.push({ { tailr + 1, tailc }, taild });
            }
            else if (taild == 3) {
                tail.push({ { tailr - 1, tailc }, taild });
            }
            
        }
        // 사과 먹은 경우는 꼬리가 그대로 있어야 함
        else {
            tail.push({ { tailr, tailc }, taild });
        }
    }

    return 0;
}
