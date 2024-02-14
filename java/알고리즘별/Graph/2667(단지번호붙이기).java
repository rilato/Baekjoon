import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int answer = 0;
    static int[] dr = { -1, 1, 0, 0 };
    static int[] dc = { 0, 0, -1, 1 };
    static int[][] arr;
    static boolean[][] visited;
    static ArrayList<Integer> ans = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        visited = new boolean[N][N];

        for (int i = 0; i < N; i++) {
            String S = br.readLine();

            for (int j = 0; j < N; j++) {
                arr[i][j] = S.charAt(j) - '0';
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && arr[i][j] == 1) {
                    int cnt = BFS(i, j);
                    ans.add(cnt);
                    answer++;
                }
            }
        }

        // ArrayList를 정렬하려면, Arrays.sort가 아닌, Collections.sort를 사용한다.
        Collections.sort(ans);

        bw.write(Integer.toString(answer) + '\n');

        for (int i = 0; i < ans.size(); i++) {
            bw.write(Integer.toString(ans.get(i)) + '\n');
        }

        br.close();
        bw.flush();
        bw.close();
    }

    // Java에는 Pair가 없다. 따라서 Pair를 만들어주어야 한다. static을 사용하여 전역변수화 해준다.
    public static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() {
            return first;
        }

        public int getSecond() {
            return second;
        }
    }

    public static int BFS(int row, int col) {
        int count = 0;
        // 직접 만든 Pair 클래스를 적용하고, LinkedList<>()를 통해 초기화해준다.
        Queue <Pair> q = new LinkedList<>();

        // push가 아닌 add 함수를 사용한다.
        q.add(new Pair(row, col));
        visited[row][col] = true;
        count++;

        // empty()가 아닌 isEmpty()를 사용한다.
        while (!q.isEmpty()) {
            // front()가 아닌 peek()를 사용한다.
            int r = q.peek().getFirst();
            int c = q.peek().getSecond();

            // pop()이 아닌 remove()를 사용한다.
            q.remove();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visited[nr][nc] && arr[nr][nc] == 1) {
                    q.add(new Pair(nr, nc));
                    visited[nr][nc] = true;
                    count++;
                }
            }
        }

        return count;
    }
}