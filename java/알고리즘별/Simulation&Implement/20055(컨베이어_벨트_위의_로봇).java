import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int cnt = 0;
        int answer = 0;
        int[] durability = new int[2 * N];
        boolean[] robot = new boolean[N];

        StringTokenizer st1 = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < 2 * N; i++) {
            durability[i] = Integer.parseInt(st1.nextToken());
        }

        while(true) {
            // 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
            int temp = durability[2 * N - 1];
            for (int i = 2 * N - 1; i >= 1; i--) {
                durability[i] = durability[i - 1];
            }
            durability[0] = temp;

            boolean tmp = robot[N - 1];
            for (int i = N - 1; i >= 1; i--) {
                robot[i] = robot[i - 1];
            }
            robot[0] = tmp;
            robot[N - 1] = false;   // "언제든지" 로봇이 내리는 위치에 도달하면 그 즉시 내린다.

            // 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
            for (int i = N - 2; i >= 0; i--) {
                if (robot[i] == true && robot[i + 1] == false && durability[i + 1] >= 1) {
                    robot[i + 1] = true;
                    robot[i] = false;
                    durability[i + 1]--;

                    if (durability[i + 1] == 0) {
                        cnt++;
                    }
                }
            }
            robot[N - 1] = false;   // "언제든지" 로봇이 내리는 위치에 도달하면 그 즉시 내린다.

            // 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
            if (robot[0] == false && durability[0] >= 1) {
                robot[0] = true;
                durability[0]--;

                if (durability[0] == 0) {
                    cnt++;
                }
            }

            // 단계를 진행한다.
            answer++;

            // 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다
            if (cnt >= K) {
                bw.write(Integer.toString(answer));
                break;
            }
        }

        br.close();
        bw.flush();
        br.close();
    }
}